
readline
================

Tiny C readline library, note: this is not used in CLI-readline's one.


Installation
==================

Install with git

```bash
git clone https://github.com/yorkie/readline.git master
```

Usage
=================

```c
#include "readline.h"

readline_t * rl = readline_new(text);
char * line;

do {
  line = readline_next(rl);
  // get line.

} while (line != NULL);
```

License
===================

MIT