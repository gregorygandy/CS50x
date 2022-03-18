from cs50 import get_string


def main():
    text = get_string("Text: ")
    letter_cn = letters(text)
    words_cn = words(text)
    sentences_cn = sentences(text)
    L = (100 / words_cn) * letter_cn
    S = (100 / words_cn) * sentences_cn
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade:", index)


def letters(text):
    letter_cn = 0
    for i in text:
        if i.isalpha() == True:
            letter_cn = letter_cn + 1
    return letter_cn


def words(text):
    word_cn = 1  # need to count first word of text which is not preceded by " "
    for i in text:
        if i == " ":
            word_cn = word_cn + 1
    return word_cn


def sentences(text):
    sentence_cn = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            sentence_cn = sentence_cn + 1
    return sentence_cn


main()