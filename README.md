<h1 align="center">1337🇲🇦_Minishell_42 🐚  Kaneki</h1>
<p align="center">
  <a href="https://github.com/KanekiEzz/1337_Minishell_42">
    <img src="https://raw.githubusercontent.com/KanekiEzz/kaneki_badges/refs/heads/main/minishellm.png" alt="42 Badge">
  </a>
</p>

---

# 👨‍💻 Author ✍🏼

<table>
  <tr>
    <td align="center"><a href="https://github.com/KanekiEzz/"><img src="https://avatars.githubusercontent.com/u/110631781?s=400&u=0cd1de60c073f367d291df9c6ccef5c18ac64e41&v=4" width="100px;" alt="100px"/>
      <br />
    </a>
      <br />
      <a href="https://profile.intra.42.fr/users/iezzam" title="Intra 42">
        iezzam42  🇲🇦
      </a>
    </td>
        <td align="center"><a href="https://github.com/iaceene/"><img src="https://avatars.githubusercontent.com/u/106110604?v=4" width="100px;" alt="100px"/>
      <br />
    </a>
      <br />
      <a href="https://profile.intra.42.fr/users/yaajagro" title="Intra 42">
        yaajagro42  🇲🇦
      </a>
    </td>
  </tr>
</table>

---

## 📝 Program Name: **minishell**

### 📜 Description
The goal of this project is to implement a simple shell, `minishell`, that mimics the basic functionality of the bash shell. It should provide a prompt, handle user input, support basic shell built-ins, implement redirections, pipes, and handle environment variables. The shell should also properly manage signals like `ctrl-C`, `ctrl-D`, and `ctrl-\`, and support command history using the `readline()` function. 🚀

### 📁 Mandatory Files
- `Makefile` 🔧
- `*.h` (Header files) 🗂️
- `*.c` (Source files) 💻

### ⚙️ Makefile
The following rules should be implemented in the `Makefile`:
- `NAME`: Name of the program 🏷️
- `all`: Compiles the project 🛠️
- `clean`: Removes object files 🧹
- `fclean`: Removes object files and the compiled program 🗑️
- `re`: Recompiles everything 🔄

### 🔌 External Functions
You are allowed to use the following external functions:
- `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`
- `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`
- `fork`, `wait`, `waitpid`, `wait3`, `wait4`
- `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`
- `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`
- `dup`, `dup2`, `pipe`
- `opendir`, `readdir`, `closedir`
- `strerror`, `perror`
- `isatty`, `ttyname`, `ttyslot`, `ioctl`
- `getenv`, `tcsetattr`, `tcgetattr`
- `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

**Libft is authorized**: You can use your own `libft` (if applicable) 🧶.

### ✔️ Requirements
1. **Prompt**: Your shell must display a prompt when waiting for a new command. ⏳
2. **History**: Command history should be supported. 📝
3. **Execution**: 
   - Search and launch the right executable based on the `PATH` variable, or a relative/absolute path. 🚀
   - Avoid using more than one global variable for signal information. 🚫
4. **Quoting**:
   - Handle `"` (double quotes) and `'` (single quotes) properly to prevent the shell from interpreting metacharacters. 🔒
   - Double quotes allow `$` (dollar sign) expansion, while single quotes do not. 🗣️
5. **Redirection**:
   - `<`: Redirect input. ⬅️
   - `>`: Redirect output. ➡️
   - `<<`: Accept a delimiter and read until the delimiter is seen. 🏁
   - `>>`: Redirect output in append mode. 🔄
6. **Pipes**: Implement pipes (`|`) to connect the output of one command to the input of the next. 🔗
7. **Environment Variables**: Expand environment variables like `$HOME`. 🌍
8. **Special Expansion**: Handle `$?` for the exit status of the last foreground process. 🔢
9. **Signal Handling**:
   - `ctrl-C`: Display a new prompt on a new line. ↩️
   - `ctrl-D`: Exit the shell. 🚪
   - `ctrl-\`: Do nothing. ❌
10. **Built-ins**:
    - `echo` with `-n` option. 🗣️
    - `cd` with relative or absolute paths only. 🛤️
    - `pwd` with no options. 🏠
    - `export` with no options. 🌿
    - `unset` with no options. 🚫
    - `env` with no options or arguments. 🌐
    - `exit` with no options. 🚪

### 🧠 Memory Management
- The `readline()` function can cause memory leaks (not your responsibility to fix). 💧
- However, **you are responsible for ensuring that your code does not cause memory leaks**. 🔒

### 🚫 Limitations
- Limit your functionality to what's described here. Anything not specified is **not** required. 🛑
- Use bash as a reference for expected behavior. 🐚

### 🧑‍💻 Example of Usage
1. **Starting the Shell**:
   ```sh
   ./minishell
   ```
2. **Basic Commands**:
   - `echo Hello, World!` 🌍
   - `pwd` 🏠
   - `cd /path/to/dir` 🛤️
   - `exit` 🚪

3. **Redirections**:
   - `echo "Hello" > output.txt` 📝
   - `cat < input.txt` 📖
   - `cat > output.txt << EOF` 🗣️
   - `ls >> output.txt` 🧳

4. **Pipes**:
   - `echo "Hello" | grep "Hello"` 🔗

5. **Environment Variables**:
   - `echo $HOME` 🌍
   - `echo $PATH` 🛤️

6. **Signal Handling**:
   - `ctrl-C`: Displays the prompt again on a new line. ↩️
   - `ctrl-D`: Exits the shell. 🚪

### 🛠️ Compilation
To compile the program, run the following command:

```sh
make
```

This will generate the `minishell` executable. ⚡

### 🧹 Cleaning Up
To remove object files and the executable, run:

```sh
make clean
make fclean
```

### 🔄 Recompiling
To recompile the project from scratch:

```sh
make re
```

---

This README provides an outline of the mandatory requirements and guidelines for the **minishell** project. Make sure to follow these instructions closely to meet the project's specifications. 📝

