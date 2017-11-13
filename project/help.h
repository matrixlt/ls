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

	printf("如何显示条目\n");
	fputs("\
			-l		use a long listing format\n\
			-g		like -l, but do not list owner\n\
			-G, --no-group\n\
					in a long listing, don't print group names\n\
			-n, --numeric-uid-gid\n\
					like - l, but list numeric user and group IDs\n\
			-o		like -l, but do not list group information\n", stdout);
	
	printf("如何排序");
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
	
	printf("是否显示编号\n");
	fputs("\
			-i		print the index number of each file\n", stdout);
	
	printf("是否显示颜色\n");
	fputs("\
			--color[=WHEN]\n\
					colorize  the output; WHEN can be 'always' (default if omitted),\n\
					'auto', or 'never'; more info below\n", stdout);
	
	printf("是否显示文件大小\n");
	fputs("\n\
			-s		print the allocated size of each file, in blocks\n", stdout);
	
	printf("如何显示文件名\n");
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
					print raw entry names(don't treat e.g. control characters  spe?\\n\
					cially)\n", stdout);
	
	printf("特殊命令\n");
	fputs("\
			--help\n\
					display this help and exit\n\
			--version\n\
					output version information and exit\n", stdout);
}