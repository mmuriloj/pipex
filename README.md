<p align="center"><img src="https://game.42sp.org.br/static/assets/achievements/pipexe.png"> </p>
<p align="center"><b>succeeded with 100%</b></p>


# PIPEX
This project mimics the behavior of pipe operator <b>"|"</b>.

## Mandatory goal
The program will be executed as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```
It must take 4 arguments:
- <b>file1</b> and  <b>file2 </b> are file names.
- <b>cmd1</b> and <b>cmd2</b> are shell commands with their parameters.
It must behave exactly the same as the shell command below:
```bash
$> < file1 cmd1 | cmd2 > file2
```

## Makefile and use
In order to compile pipex, one must type `make` one the root folder.

## Examples
`./pipex infile "ls -l" "wc -l" outfile` should behave like ` < infile ls -l | wc -l > outfile`

and

`./pipex infile "grep a1" "wc -w" outfile` should behave like ` < infile grep a1 | wc -w > outfile`
