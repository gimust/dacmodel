// MASH Simulation
// http://www.holmea.demon.co.uk/Frac2/Mash.htm

#include <stdint.h>
#include <string>

class mash3
{
public:
    mash3();
    mash3(uint32_t mod1, uint32_t mod2, uint32_t mod3);
    int Clock(int n = 1);
    std::string getState();

private:
    void init();

    uint32_t modulo1;
    uint32_t modulo2;
    uint32_t modulo3;

    int q[3];       // Latch outputs
    int c[3][3];    // Carry flip flops
    int mash;       // Output value
};
