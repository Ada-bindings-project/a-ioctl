#include <sys/ioctl.h>
unsigned testIOC() {
  return _IOC(0x01, 0x02,0x04,0x08);

}

unsigned testIO() {
  return _IO(0x01, 0x02);

}
unsigned testIOR() {
  return _IOR(0x01, 0x02,0x04);

}
unsigned testIOW() {
  return _IOW(0x01, 0x02,0x04);

}
unsigned testIOWR() {
  return _IOWR(0x01, 0x02,0x04);
}

unsigned testIOR_BAD() {
  return _IOR_BAD(0x01, 0x02,0x04);

}
unsigned testIOW_BAD() {
  return _IOW_BAD(0x01, 0x02,0x04);

}


unsigned testIO_DIR() {
  return _IOC_DIR(0x12345678);

}

unsigned testIO_TYPE() {
  return _IOC_TYPE(0x123456);

}

unsigned testIO_SIZE() {
  return _IOC_SIZE(0x123456);

}
