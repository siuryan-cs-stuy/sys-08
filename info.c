#include <time.h>
#include <sys/stat.h>
#include <stdio.h>


void print_size(size_t size) {
  char str[100];
  size_t gb = 0;
  size_t mb = 0;
  size_t kb = 0;
  size_t b = size;
  kb = b / 1024;
  b = b % 1024;
  mb = kb / 1024;
  kb = kb % 1024;
  gb = mb / 1024;
  mb = mb % 1024;
  sprintf(str, "%luGB %luMB %luKB %luB", gb, mb, kb, b);
  printf("file size: %s\n", str);
}

void print_permissions(mode_t permissions) {
  permissions = permissions % 01000;
  printf("permissions: %o\n", permissions);
}

int main() {

  struct stat sb;
  stat("info.c", &sb);

  print_size(sb.st_size);
  print_permissions(sb.st_mode);
  printf("time accessed: %s\n", ctime( &sb.st_atime ));

  return 0;

}
