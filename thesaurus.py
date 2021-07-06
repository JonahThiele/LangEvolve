from nltk.corpus import wordnet
import sys

word = sys.argv[1]

synonyms = []
antonyms = []

for syn in wordnet.synsets(word):
	for l in syn.lemmas():
		synonyms.append(l.name())
		if l.antonyms():
			antonyms.append(l.antonyms()[0].name())

file = open("OutThesaurus.txt", "w")
for word in synonyms:
	file.write(word + '\n')
for word in antonyms:
	file.write(word + '\n')

file.close() 