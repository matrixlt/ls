#include<stdio.h>
#include<stdlib.h>

void help() {
	printf("显示哪些条目\n");
	fputs("\
			-a		do not ignore entries starting with .\n\
			-A		do not list implied . and ..\n\
			--hide=PATTERN\n\
					do not list implied entries matching shell PATTERN(overridden\n\
					by - a or -A)\n\
			-B		do not list implied entries ending with ~\n", stdout);

	printf("\n如何显示条目\n");
	fputs("\
			-l		use a long listing format\n\
			-g		like -l, but do not list owner\n\
			-G, --no-group\n\
					in a long listing, don't print group names\n\
			-n, --numeric-uid-gid\n\
					like - l, but list numeric user and group IDs\n\
			-o		like -l, but do not list group information\n\
			--time=WORD\n\
					with -l, show time as WORD instead of default modification time:\n\
					atime  or  access  or  use  (-u); ctime or status (-c); also use\n\
					specified time as sort key if --sort=time (newest first)\n", stdout);
	
	printf("\n如何排序\n");
	fputs("\
			-c      with -lt: sort by, and show, ctime (time of last modification of\n\
					file status information); with - l: show ctime and sort by  name;\n\
					otherwise: sort by ctime, newest first\n\
			--group-directories-first\n\
					group directories before files;\n\
					can be augmented with a --sort  option, but any use of\n\
					--sort = none(-U) disables grouping\n\
			-r		reverse order while sorting\n\
			-S		sort by file size, largest first\n\
			-t		sort by modification time, newest first\n\
			-X		sort alphabetically by entry extension\n\
			--sort=WORD\n\
					sort  by  WORD instead of name: none (-U), size (-S), time (-t),\n\
					version(-v), extension(-X)\n\
			-u		with  -lt:  sort by, and show, access time; with -l: show access\n\
					time and sort by name; otherwise: sort by  access  time, newest first\n\
			-U		do not sort; list entries in directory order\n\
			-v		natural sort of (version) numbers within text\n\
			-f		do not sort, enable -aU, disable -ls --color\n", stdout);
	
	printf("\n如何显示时间\n");
	fputs("\
			--time-style=STYLE\n\
					with -l, show times using style STYLE: full-iso, long-iso,  iso,\n\
              				locale,  or  +FORMAT;  FORMAT  is interpreted like in 'date'; if\n\
              				FORMAT  is  FORMAT1<newline>FORMAT2,  then  FORMAT1  applies  to\n\
              				non-recent  files  and FORMAT2 to recent files; if STYLE is pre‐\n\
              				fixed with 'posix-', STYLE takes effect only outside  the  POSIX\n\
              				locale\n", stdout);



	printf("\n是否显示作者\n");
	fputs("\
			--author\n\
              				with -l, print the author of each file\n ", stdout);
	

	printf("\n是否显示编号\n");
	fputs("\
			-i		print the index number of each file\n", stdout);
	

	printf("\n是否显示颜色\n");
	fputs("\
			--color[=WHEN]\n\
					colorize  the output; WHEN can be 'always' (default if omitted),\n\
					'auto', or 'never'; more info below\n", stdout);
	
	printf("\n是否显示文件大小\n");
	fputs("\n\
			-s		print the allocated size of each file, in blocks\n", stdout);
	
	printf("\n如何显示文件大小\n");
	fputs("\
			-h, --human-readable\n\
              				with -l and/or -s, print human readable sizes (e.g., 1K 234M 2G)\n\
			--si   		likewise, but use powers of 1000 not 1024\n\
			-k, --kibibytes\n\
              				default to 1024-byte blocks for disk usage\n", stdout);

	printf("\n如何显示文件名\n");
	fputs("\
			-F		append indicator (one of */=>@|) to entries\n\
			--file-type\n\
					likewise, except do not append '*'\n\
			-p		append / indicator to directories\n\
			--indicator-style=WORD\n\
					append indicator with style WORD to entry names : none(default),\n\
					slash(-p), file - type(--file - type), classify(-F)\n\
			-Q		enclose entry names in double quotes\n\
			-N, --literal\n\
					print raw entry names\n", stdout);
	
	printf("\n特殊命令\n");
	fputs("\
			-R, --recursive            list subdirectories recursively\n\
			--help\n\
					display this help and exit\n\
			--version\n\
					output version information and exit\n", stdout);
}