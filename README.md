# Magra

Magra is a vocabulary management and word and phrase generation program aimed at conlangers.
It is written in C++ and uses Qt for the GUI. This is my first real project in this language.

[insert screenshot here when it’s done]

## Features

Groups management
- [ ] Create a group with a name and description
- [ ] View and edit a name and description
- [ ] Add a subgroup to a group
- [ ] List all existing groups in a tree structure
- [ ] Move a group from a group to another

Words management
- [ ] Add a new word to a group (text, meaning and description)
- [ ] Remove a word from a group
- [ ] View and edit a word (text, meaning and description)
- [ ] Move a word from a group to another
- [ ] List all words in a group (optionally with subgroups)

Word derivations
- [ ] Create a word derivation pattern associated with a group (*regexp?*)
- [ ] View and edit a name and description
- [ ] Apply the pattern to words in the group to make new words
- [ ] New words shall be stored in the same group or in another

Phrase construction
- [ ] Create finite-state automatons for syntactical structures (not associated with a group)
- [ ] View and edit a name and description
- [ ] Each automaton can include derivation patterns
- [ ] Use these automatons to generate random phrases

File management
- [ ] Save a given group, all its subgroups, words, derivations patterns and automatons to a JSON file
- [ ] Load a group from a file and add it to the current tree

## Compilation and use

Be sure to have Qt5 installed on your computer.

```
qmake-qt5 && make
./magra
```
