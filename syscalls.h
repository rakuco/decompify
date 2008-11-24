;;
;; MC404ABCD - 2008s2
;; Projeto 2
;;
;; 071294 - Jorge Augusto Hongo
;; 072201 - Raphael Kubo da Costa
;;
;;     Copyright (C) 2008  Jorge Augusto Hongo
;;     Copyright (C) 2008  Raphael Kubo da Costa
;;
;;     This program is free software: you can redistribute it and/or modify
;;     it under the terms of the GNU General Public License as published by
;;     the Free Software Foundation, either version 3 of the License, or
;;     (at your option) any later version.
;;
;;     This program is distributed in the hope that it will be useful,
;;     but WITHOUT ANY WARRANTY; without even the implied warranty of
;;     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;     GNU General Public License for more details.
;;
;;     You should have received a copy of the GNU General Public License
;;     along with this program.  If not, see <http://www.gnu.org/licenses/>.
;;

%ifndef _SYSCALLS_H
%define _SYSCALLS_H

; Syscall numbers
%define SYS_EXIT    1
%define SYS_READ    3
%define SYS_WRITE   4
%define SYS_OPEN    5
%define SYS_CLOSE   6
%define SYS_LSEEK   19

; Interrupt
%define LINUX_CALL  0x80

; Default stream numbers
%define STDIN       0
%define STDOUT      1

; The following error codes were taken from <sysexits.h>
%define EX_OK       0
%define EX_USAGE    64
%define EX_DATAERR  65

; File access modes
%define O_RDONLY    0
%define O_WRONLY    1
%define O_RDWR      2
%define O_CREAT     100q
%define O_TRUNC     1000q

; Seek constants
%define SEEK_SET    0
%define SEEK_CUR    1
%define SEEK_END    2

; Modes
%define S_IRWXU 00700q
%define S_IRUSR 00400q
%define S_IWUSR 00200q
%define S_IXUSR 00100q

%define S_IRWXG 00070q
%define S_IRGRP 00040q
%define S_IWGRP 00020q
%define S_IXGRP 00010q

%define S_IRWXO 00007q
%define S_IROTH 00004q
%define S_IWOTH 00002q
%define S_IXOTH 00001q

%macro sys_close 1
  push ebx
  mov eax, SYS_CLOSE
  mov ebx, %1
  int LINUX_CALL
  pop ebx
%endmacro

%macro sys_exit 0-1 0
  mov eax, SYS_EXIT
  mov ebx, %1
  int LINUX_CALL
%endmacro

%macro sys_open 1-3 O_RDONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
  push ebx
  mov eax, SYS_OPEN
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int LINUX_CALL
  pop ebx
%endmacro

%macro sys_lseek 2-3 SEEK_SET
  push ebx
  push ecx
  push edx
  mov eax, SYS_LSEEK
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int LINUX_CALL
  pop edx
  pop ecx
  pop ebx
%endmacro

%macro sys_read 3
  push ebx
  push ecx
  push edx
  mov eax, SYS_READ
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int LINUX_CALL
  pop edx
  pop ecx
  pop ebx
%endmacro

%macro sys_write 3
  push ebx
  push ecx
  mov eax, SYS_WRITE
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int LINUX_CALL
  pop ecx
  pop ebx
%endmacro

%endif

; vim:syntax=nasm
