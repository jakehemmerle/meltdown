static sigjmp_buf jbuf;

static void catch_segv()
{
  siglongjmp(jbuf, 1);
}

int main() {
  unsigned long kernel_data_addr = 0xfb61b000;

  signal(SIGPIPE, catch_segv);

  if (sigsetjmp(jbuf, 1) == 0) { 
    char kernel_data = *(char*)kernel_data_addr;
    printf("kernel data at address 0x%lu is %c\n", kernel_data_addr, kernel_data);
  } else {
    printf("unaccessable!\n");
  }

  printf("Program continues!!\n");

  return 0;
}