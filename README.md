# C++ String Practice - Rustlings Style

A collection of C++ string manipulation exercises for competitive programming (OI) preparation.

## Structure

```
exercises/
├── 01_basics/         # String initialization, concatenation, access
├── 02_operations/     # substr, find, replace, number conversion
├── 03_search/         # Advanced search operations
├── 04_regex/          # Regular expressions (std::regex)
└── 05_advanced/       # string_view, split, join, trim, prefix/suffix
```

## How to Use

### Run All Exercises
```bash
python3 runner.py
```

### Run Specific Exercise
```bash
python3 runner.py 01_basics/01_init.cpp
```

### How to Solve

1. Each exercise file contains `// FIX THIS` markers
2. Read the TODO comments to understand what's needed
3. Fix the code to make assertions pass
4. Run the runner to verify

## Exercise List

### 01_basics (4 exercises)
- `01_init.cpp` - String constructors
- `02_concat.cpp` - Concatenation (+, +=, append)
- `03_access.cpp` - Character access ( [], at, front, back)
- `04_io.cpp` - Input handling (>>, getline)

### 02_operations (4 exercises)
- `01_substr.cpp` - Substring extraction
- `02_find.cpp` - Finding substrings (find, npos)
- `03_replace.cpp` - Replace, erase, insert
- `04_numbers.cpp` - Number conversion (to_string, stoi)

### 03_search (1 exercise)
- `01_search.cpp` - Advanced find operations

### 04_regex (3 exercises)
- `01_match.cpp` - regex_match for validation
- `02_search.cpp` - regex_search to find all matches
- `03_replace.cpp` - regex_replace with capture groups

### 05_advanced (5 exercises)
- `01_string_view.cpp` - Zero-copy string_view
- `02_manual_split.cpp` - Implement split function
- `03_join.cpp` - Implement join function
- `04_trim.cpp` - Trim whitespace
- `05_prefix_suffix.cpp` - startsWith, endsWith, stripPrefix, stripSuffix

## Requirements

- Python 3
- g++ with C++17 support

## Notes

- Use `-std=c++17` for string_view support
- std::regex can be slow in competitive programming - know when to use manual parsing instead
- string_view is crucial for OI performance (no unnecessary copies)
# cpp_string_tricks
