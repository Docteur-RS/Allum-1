int rawing
{
  struct termios termi;

  tgetent(NULL,  "xterm");
  tcgetattr(0, &termi);
  termi.c_cc[VMIN] = 1;
  termi.c_cc[VTIME] = 0;
  termi.c_lflag &= ~(IGNBRK);
  tcsetattr(0, TCSADRAIN, &termi);
}

struct termios termios
tgentent(NULL, "xterm")
  tcgetattr(kkkk)
