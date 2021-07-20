user_text = input("Text: ")


def counting_letters(text):
    # sourcery skip: inline-immediately-returned-variable, simplify-constant-sum, sum-comprehension
    """Method used to count letter in the text"""
    n_letters = 0
    for letter in text:
        if letter.isalpha():
            n_letters += 1
    return n_letters


def counting_words(text):
    """It sums 1 for word in the text, text is split by blank space"""
    return sum(1 for word in text.split(" "))


def counting_sentences(text):
    """suming each sentence that end in the correcondent characters"""
    return sum(text[i] in [".", "?", "!"] for i in range(len(text)))


#print(letters, words, sentences)

def coleman_liau():
    letters = counting_letters(user_text)
    words = counting_words(user_text)
    sentences = counting_sentences(user_text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade >= 16:
        return "Grade 16+"
    elif grade < 1:
        return "Before Grade 1"
    else:
        return "Grade {}".format(grade)


# calling the function to calculate de grade.
print(coleman_liau())
