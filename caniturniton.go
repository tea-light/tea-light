package main

import (
	"fmt"
	"golang.org/x/net/html"
	"log"
	"net/http"
	"strconv"
)

func handler(w http.ResponseWriter, r *http.Request) {
	res, err := get()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s %.2f\n", r.URL.Path, res)
	if res <= 50.0 {
		fmt.Fprintf(w, "no")
	} else {
		fmt.Fprintf(w, "yes")
	}
}

func main() {
	fmt.Printf("Listening on port 8081 ... \n")
	http.HandleFunc("/", handler)
	http.ListenAndServe(":8081", nil)
}

func get() (f float64, err error) {
	response, err := http.Get("http://realtimeweb-prod.nationalgrid.com/Frequency60min.aspx")
	if err != nil {
		return f, err
	} else {
		defer response.Body.Close()
		z := html.NewTokenizer(response.Body)
		val := ""
		for {
			tt := z.Next()
			switch {
			case tt == html.ErrorToken:
				// End of the document, we're done
				f, err := strconv.ParseFloat(val, 64)
				if err != nil {
					return f, err
				}
				return f, nil
			case tt == html.StartTagToken || tt == html.SelfClosingTagToken:
				t := z.Token()
				isAnchor := t.Data == "area"
				if isAnchor {
					for _, a := range t.Attr {
						if a.Key == "alt" {
							val = a.Val
						}
					}
				}
			}
		}
	}
}
