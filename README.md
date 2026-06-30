# Student Record Management System

A C program to manage student records using a singly linked list with persistent file storage.

## Features

- **Add Record** — Auto-assigns smallest available roll number (no duplicates)
- **Delete Record** — By roll number or by name (shows matches, then delete by roll)
- **Show Records** — Tabular display of all records
- **Modify Record** — Search by roll/name/percentage, then edit name or percentage
- **Save / Load** — Binary file (`student.dat`) for persistent storage
- **Sort** — By name (alphabetical) or by percentage (ascending)
- **Exit** — Save & exit or exit without saving

## File Structure

| File | Purpose |
|------|---------|
| `main.c` | Main menu loop, sort functions, memory cleanup |
| `stud_add.c` | Add new record with auto roll number assignment |
| `stud_del.c` | Delete record by roll number or name |
| `stud_show.c` | Display all records in table format |
| `stud_mod.c` | Search and modify existing records |
| `stud_save.c` | Save to / load from `student.dat` |
| `student.h` | Header file with struct, declarations, and macros |

## Compilation

Requires a C compiler (GCC, MinGW, MSVC, etc.):

```bash
cc  main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c
```

## Usage

```bash
./student
```

Follow the on-screen menu:

```
**** STUDENT RECORD MENU ****

A/a : Add New Record
D/d : Delete a Record
S/s : Show the List
M/m : Modify a Record
V/v : Save
T/t : Sort the List
E/e : Exit
```

## Data Persistence

Records are stored in `student.dat` (binary format). Data is loaded automatically on startup and saved on demand (V/v) or on save-and-exit.

## Concepts Demonstrated

- pointer, arrays, string, functions.
- Singly linked list (dynamic memory allocation with `malloc`/`free`)
- Multi-file C programming (header files, `extern`, separate compilation)
- Binary file I/O (`fread`/`fwrite`)
- Bubble sort on linked list

- ## Screenshots

| Feature | Screenshot |
|---------|------------|
| Main Menu | `main.png` |
| Add Record | `add.png` |
| Show Records | `show.png` |
| Modify Record | `modify.png` |
| Sort Records | `sort.png` |
| Save & Exit | `exit.png` |


