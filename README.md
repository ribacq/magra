# Magra

Magra is a vocabulary management and sentence generation program aimed at conlangers.
It is written in C++. This is my first real project in this language.

## What should you be able to do?

Groups management
- [x] Create a group with a name and description
- [x] Read and write a group’s name and description
- [x] Add a subgroup to a group
- [ ] List all existing groups in a tree structure
- [x] Move a group from a group to another

Words management
- [x] Add a new word to a group (text, meaning and description)
- [x] Remove a word from a group
- [x] Edit a word (change text and meaning)
- [x] Move a word from a group to another
- [x] List all words in a group (optionally with subgroups)

Word derivations
- [ ] Create a word derivation pattern associated with a group
- [ ] A derivation pattern should have a name and description (editable)
- [ ] Apply the pattern to words in the group to make new words
- [ ] New words shall be stored in the same group or in another

Phrase construction
- [ ] Create finite-state automatons for syntactical structures, associated with a group
- [ ] Each automaton can use words from its group and subgroups, and include derivation patterns
- [ ] Use these automatons to generate random phrases

File management
- [ ] Save a given group, all its subgroups, words, derivations patterns and automatons to a file
- [ ] Load a group from a file and add it to the current tree
