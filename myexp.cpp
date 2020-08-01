#include <cstdint>
#include <iostream>

extern "C" {

uint32_t fixed8exp(uint32_t r) {
  uint32_t p = 8;
  uint32_t c0 = (0x00000001 << p) * 2;
  uint32_t c2 = (0x00000001 << p) / 6; //0x0000002a;

  uint32_t r2 = (r * r) >> p;

  uint32_t remez = c0 + ((r2 * c2) >> p); // R(r^2)

  uint32_t den = remez - r;
  // 1 + r * 2 / (R(r^2) - r)
  return (0x00000001 << p) + (r << (p + 1)) / den;
}

uint32_t mymul(uint32_t a, uint32_t b) {
  uint32_t p = 8;
  uint32_t m = (0x1 << p) - 1;
  uint32_t ai = a >> p;
  uint32_t af = a & m;
  uint32_t bi = b >> p;
  uint32_t bf = b & m;
  return a * bi + ai * bf + ((af * bf) >> p);
}


uint32_t myexp(uint32_t r) {
  uint32_t p = 8;
  uint32_t thresh = (0x00000001 << (p - 1));
  if (r <= thresh) {
    return fixed8exp(r);
  } else {
    return mymul(myexp(r >> 1), myexp((r + 1) >> 1));
  }

}

uint32_t looplim = 4096 * 2;

uint32_t ledtime(uint32_t x) {
  return (myexp(x) - 0x000000f2) >> 18;
}


}


// int main() {

//   std::cout << myexp(0x00f00000) << '\n';
//   std::cout << myexp(0x01000000) << '\n';
//   std::cout << myexp(0x01100000) << '\n';
  
//   return 0;
// }
