import csv

# Reading the csv file
with open("large.csv", "r") as data_set:
    data_reader = csv.DictReader(data_set)
    # extracting the header with out the "name" column
    for row in data_reader:
        dna_headers = list(row.keys())[1:]
# print(dna_headers)

# reading the txt file
with open("5.txt", "r") as STR_sequence:
    str_line = STR_sequence.readlines()[0]
# print(str_line[0])

# feeding the dna dictionary with the str and the time it has been found with in the txt file
person_dna = {}
found = 0
for dna in dna_headers:
    for i in range(len(str_line)):
        sub = str_line[i:i + len(dna)]
        next_str = str_line[i + len(dna): (i + len(dna)) + len(dna)]
        if dna == sub and dna == next_str:
            found += 1
            person_dna[dna] = found + 1
    found = 0
print(person_dna)

# finding the person

with open("large.csv", "r") as data_set:
    found = False
    data_reader = csv.DictReader(data_set)
    for row in data_reader:
        flag = True
        for strs in dna_headers:
            if int(row[strs]) != person_dna[strs]:
                flag = False
        if flag:
            print(row["name"])
            found = True
    if not found:
        print("No match")
