<img width="265"  src="https://user-images.githubusercontent.com/57855070/111369447-bfc1c000-869f-11eb-9951-c6a71e048078.png"> <img width="165"  src="https://user-images.githubusercontent.com/57855070/111369604-eb44aa80-869f-11eb-8413-4775047814d6.png">

This project was done as part of an "Advanced Programming" course at Ariel University. <br/>
In this project I implemented some of the functions of the [ed](https://en.wikipedia.org/wiki/Ed_(text_editor)) editor that is in the Linux system

To implement some of the functions I used a regular expression by a [library in cpp](https://en.cppreference.com/w/cpp/regex)

##### The functions I implemented:
* **p:**  Print the current line.
* **x:**  Updating current line to x.
* **+x:**  Move x lines forward in the document, the current line is now x.
* **-x:**  Go back x lines, the current line is now x.
* **$:**  Go to the last line, the current line is now the last.
* **a:**  Add one or more rows after the current row.
* **i:**  Add one or more rows before the current row.
* **c:**  Replace the current row with one or more rows.
* **d:**  Delete the current line.
* **j:**  Connect the current line with the line following it.
* **W:**   Write the document to the file.
* **/text/:**  Look forward the next line that contains the text string.
* **s/old/new:**  Replace the first instance of the old string with the new string in the current row.
