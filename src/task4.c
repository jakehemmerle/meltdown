int main() {
  char *kernel_data_addr = (char*)0xf9e60000;
  char kernel_data = *kernel_data_addr;
  printf("I have readhed here.\n");
  return 0;
}