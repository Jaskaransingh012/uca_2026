#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  FILE *file_ptr = fopen(argv[1], "r");
  FILE *output = fopen(argv[2], "w");

  if (file_ptr == NULL) {
    perror("Error opening file");
    return 1;
  }

  int ch;

  while ((ch = fgetc(file_ptr)) != EOF) {
    if (ch == '"') {
      fputc(ch, output);

      while ((ch = fgetc(file_ptr)) != EOF) {
        fputc(ch, output);

        if (ch == '\\') {
          ch = fgetc(file_ptr);
          if (ch == EOF) break;
          fputc(ch, output);
        }

        else if (ch == '"') {
          break;
        }
      }
    }

    else if (ch == '\'') {
      fputc(ch, output);

      while ((ch = fgetc(file_ptr)) != EOF) {
        fputc(ch, output);

        if (ch == '\\') {
          ch = fgetc(file_ptr);
          if (ch == EOF) break;
          fputc(ch, output);
        } else if (ch == '\'') {
          break;
        }
      }
    }

    // Possible comment
    else if (ch == '/') {
      int next = fgetc(file_ptr);

      // Multi-line comment
      if (next == '*') {
        int prev = 0;

        while ((ch = fgetc(file_ptr)) != EOF) {
          if (prev == '*' && ch == '/') break;

          prev = ch;
        }
      }

      // Single-line comment
      else if (next == '/') {
        while ((ch = fgetc(file_ptr)) != EOF && ch != '\n');

        if (ch == '\n') fputc('\n', output);
      }

      // Not a comment
      else {
        if (next != EOF) ungetc(next, file_ptr);

        fputc('/', output);
      }
    }

    else {
      fputc(ch, output);
    }
  }

  fclose(file_ptr);
  fclose(output);
  return 0;
}
