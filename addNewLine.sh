#awk 'NR > 1 { print prev } { prev = "\""$0"\\n""\""}' addNewLine.txt && awk 'END{print"\""$0"\""}'  addNewLine.txt

awk '{ print "\""$0"\\n""\""}' addNewLine.txt