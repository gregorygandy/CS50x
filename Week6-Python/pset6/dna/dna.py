import sys
import csv

if len(sys.argv) != 3:
    print("error: incorrect number of command-line arguments")
    sys.exit(1)

AATG = 0
GATA = 0
TATC = 0
GAAA = 0
TCTG = 0
TCTAG = 0
AGATC = 0
TTTTTTCT = 0

currentrun_AATG = 0
currentrun_GATA = 0
currentrun_TATC = 0
currentrun_GAAA = 0
currentrun_TCTG = 0
currentrun_TCTAG = 0
currentrun_AGATC = 0
currentrun_TTTTTTCT = 0

longestrun_AATG = 0
longestrun_GATA = 0
longestrun_TATC = 0
longestrun_GAAA = 0
longestrun_TCTG = 0
longestrun_TCTAG = 0
longestrun_AGATC = 0
longestrun_TTTTTTCT = 0

with open(sys.argv[2], "r") as file:
    reader = str(list(csv.reader(file))[0][0])
    for i in range(len(reader)):
        if i < len(reader) - 4:
            if reader[i] == "A" and reader[i + 1] == "A" and reader[i + 2] == "T" and reader[i + 3] == "G":  # AATG
                AATG = 1
                if reader[i+4] == "A" and reader[i + 5] == "A" and reader[i + 6] == "T" and reader[i + 7] == "G":
                    currentrun_AATG += 1
                else:
                    currentrun_AATG = 0
                if currentrun_AATG > longestrun_AATG:
                    longestrun_AATG = currentrun_AATG
            elif reader[i] == "G" and reader[i + 1] == "A" and reader[i + 2] == "T" and reader[i + 3] == "A":  # GATA
                GATA = 1
                if reader[i+4] == "G" and reader[i + 5] == "A" and reader[i + 6] == "T" and reader[i + 7] == "A":
                    currentrun_GATA += 1
                else:
                    currentrun_GATA = 0
                if currentrun_GATA > longestrun_GATA:
                    longestrun_GATA = currentrun_GATA
            elif reader[i] == "T" and reader[i + 1] == "A" and reader[i + 2] == "T" and reader[i + 3] == "C":  # TATC
                TATC = 1
                if reader[i+4] == "T" and reader[i + 5] == "A" and reader[i + 6] == "T" and reader[i + 7] == "C":
                    currentrun_TATC += 1
                else:
                    currentrun_TATC = 0
                if currentrun_TATC > longestrun_TATC:
                    longestrun_TATC = currentrun_TATC
            elif reader[i] == "G" and reader[i + 1] == "A" and reader[i + 2] == "A" and reader[i + 3] == "A":  # GAAA
                GAAA = 1
                if i + 4 < len(reader) - 4:
                    if reader[i+4] == "G" and reader[i + 5] == "A" and reader[i + 6] == "A" and reader[i + 7] == "A":
                        currentrun_GAAA += 1
                    else:
                        currentrun_GAAA = 0
                    if currentrun_GAAA > longestrun_GAAA:
                        longestrun_GAAA = currentrun_GAAA
            elif reader[i] == "T" and reader[i + 1] == "C" and reader[i + 2] == "T" and reader[i + 3] == "G":  # TCTG
                TCTG = 1
                if reader[i+4] == "T" and reader[i + 5] == "C" and reader[i + 6] == "T" and reader[i + 7] == "G":
                    currentrun_TCTG += 1
                else:
                    currentrun_TCTG = 0
                if currentrun_TCTG > longestrun_TCTG:
                    longestrun_TCTG = currentrun_TCTG
        if i < len(reader) - 5:
            if reader[i] == "T" and reader[i + 1] == "C" and reader[i + 2] == "T" and reader[i + 3] == "A" and reader[i + 4] == "G":  # TCTAG
                TCTAG = 1
                if reader[i + 5] == "T" and reader[i + 6] == "C" and reader[i + 7] == "T" and reader[i + 8] == "A" and reader[i + 9] == "G":
                    currentrun_TCTAG += 1
                else:
                    currentrun_TCTAG = 0
                if currentrun_TCTAG > longestrun_TCTAG:
                    longestrun_TCTAG = currentrun_TCTAG
            elif reader[i] == "A" and reader[i + 1] == "G" and reader[i + 2] == "A" and reader[i + 3] == "T" and reader[i + 4] == "C":  # AGATC
                AGATC = 1
                if reader[i + 5] == "A" and reader[i + 6] == "G" and reader[i + 7] == "A" and reader[i + 8] == "T" and reader[i + 9] == "C":
                    currentrun_AGATC += 1
                else:
                    currentrun_AGATC = 0
                if currentrun_AGATC > longestrun_AGATC:
                    longestrun_AGATC = currentrun_AGATC
        if i < len(reader) - 8:
            if reader[i] == "T" and reader[i + 1] == "T" and reader[i + 2] == "T" and reader[i + 3] == "T" and reader[i + 4] == "T" and reader[i + 5] == "T" and reader[i + 6] == "C" and reader[i + 7] == "T":  # TTTTTTCT
                TTTTTTCT = 1
                if reader[i + 8] == "T" and reader[i + 9] == "T" and reader[i + 10] == "T" and reader[i + 11] == "T" and reader[i + 12] == "T" and reader[i + 13] == "T" and reader[i + 14] == "C" and reader[i + 15] == "T":
                    currentrun_TTTTTTCT += 1
                else:
                    currentrun_TTTTTTCT = 0
                if currentrun_TTTTTTCT > longestrun_TTTTTTCT:
                    longestrun_TTTTTTCT = currentrun_TTTTTTCT

longestrun_AATG = longestrun_AATG + AATG
longestrun_GATA = longestrun_GATA + GATA
longestrun_TATC = longestrun_TATC + TATC
longestrun_GAAA = longestrun_GAAA + GAAA
longestrun_TCTG = longestrun_TCTG + TCTG
longestrun_TCTAG = longestrun_TCTAG + TCTAG
longestrun_AGATC = longestrun_AGATC + AGATC
longestrun_TTTTTTCT = longestrun_TTTTTTCT + TTTTTTCT

with open(sys.argv[1], "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        person = row[0]
        if sys.argv[1] == "databases/large.csv" and longestrun_AGATC == int(row[1]) and longestrun_TTTTTTCT == int(row[2]) and longestrun_AATG == int(row[3]) and longestrun_TCTAG == int(row[4]) and longestrun_GATA == int(row[5]) and longestrun_TATC == int(row[6]) and longestrun_GAAA == int(row[7]) and longestrun_TCTG == int(row[8]):
            print(person)
            sys.exit(0)
        elif longestrun_AGATC == int(row[1]) and longestrun_AATG == int(row[2]) and longestrun_TATC == int(row[3]):
            print(person)
            sys.exit(0)
    print("No match")