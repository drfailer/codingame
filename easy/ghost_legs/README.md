# GHOST LEGS

## STATEMENT

Ghost Legs is a kind of lottery game common in Asia. It starts with a number of
vertical lines. Between the lines there are random horizontal connectors binding
all lines into a connected diagram, like the one below.

```
A  B  C
|  |  |
|--|  |
|  |--|
|  |--|
|  |  |
1  2  3
```

To play the game, a player chooses a line in the top and follow it
downwards. When a horizontal connector is encountered, he must follow the
connector to turn to another vertical line and continue downwards. Repeat this
until reaching the bottom of the diagram.

In the example diagram, when you start from A, you will end up in 2. Starting
from B will end up in 1. Starting from C will end up in 3. It is guaranteed that
every top label will map to a unique bottom label.

Given a Ghost Legs diagram, find out which top label is connected to which
bottom label. List all connected pairs.

## LINK

[GHOST_LEGS](https://www.codingame.com/training/easy/ghost-legs)
