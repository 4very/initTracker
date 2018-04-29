# Initiative Tracker

| Command | Usage | Flags |
|---|:---:|---|
| Add | `a Name` | -h -i -a |
| Damage | `d Slot #` | -f |
| Heal | `h Slot #` | -f -o |
| Load | `l filename` | |
| Add Initiative | `i Slot #` | |
| Update | `u Slot` | -a -i -h -n |


## Commands
### Add
Add someone to the Initiative Order
#### Flags
| Flag | Description | Usage |
| --- | --- | --- |
| -h | Specify Health | `a Name -h 140` |
| -i | Add Initiative | `a Name -i 7` |
| -a | Add AC | `a Name -i 22` |
---
### Damage
Specify when someone takes Damage
#### Flags
| Flag | Description | Usage |
| --- | --- | --- |
| -f | From | `d 1 15 -f 3` |
---
### Heal
Specify when someone Heals
#### Flags
| Flag | Description | Usage |
| --- | --- | --- |
| -f | From | `h 1 15 -f 3` |
| -o | Override | `h 1 10000 -o` |
---
### Load
Load party members from File
#### Formatting
```
Type
Name followed by any flags used in Add
```
#### Example
```
p
Yosei -a 20 -h 53
Thoros -h 2
Throsh -h 999 -a 999
```
#### Types of Files
| Type | Description |
| --- | --- |
| p | Specify a group of people |

---
## Flag Glossary
