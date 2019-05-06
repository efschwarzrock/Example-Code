/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  //all odd bits
  int result = 0xAA;
  result = (result << 8) + result;
  result = (result << 16) + result;
  return result;
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  //min + min = 0
  int result = x+x;
  //is x+x = 0 and x does not equal 0
  result = (!result)&(!!x);
  return result;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //gets the positions where the bits are both 1
  int ones = x&y;
  int inversex = ~x;
  int inversey = ~y;
  //gets the positions where the bits are both 0
  int zeros = inversex&inversey;
  int inverseones;
  int result;
  zeros = ~zeros;
  inverseones = ~ones;
  //returns only where they are not both 0 or not both 1
  result = inverseones&zeros;
  return result;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int usez = !x;
  int usey;
  int finaly;
  int finalz;
  int result;
  //makes usez all 1s or all 0s by using arithmetic shifting
  usez = (usez<<31);
  usez = (usez>>31);
  usey = ~usez;
  //Deleats y or z based on which on is all 0s
  finaly = y&usey;
  finalz = z&usez;
  //combines
  result = finaly|finalz;
  return result;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  //divide by 2
  int resultwithoutround = (x>>n);
  //checks if you need to add one because it is negitive and is truncated improperly
  int isneg = x>>31;
  int negn = ~n+1;
  int shift = 32+negn;
  int shiftedx = x<<shift;
  int dontaddone = (!shiftedx)|(!n);
  int addone = !dontaddone;
  int addto;
  int result;
  //creats 1 if you need to add one because it is negitive 0 otherwise
  addone = addone&isneg;
  addto = 1&addone;
  result = resultwithoutround+addto;

  return result;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  int result = (x>>31);
  result = !result;
  return result;
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
  int min = 0x80;
  int max;
  int result;
  int lastbit;
  int secondtolastbit;
  int overflow;
  int useoriginal;
  int usemin;
  int usemax;
  min = min<<24;
  max = ~min;
  result = x<<1;
  //all 1s if neg
  lastbit = x>>31;
  //all 1s if 2nd to last bit is 1
  secondtolastbit = result>>31;
  //it overflowed if the 2 arn't the same
  overflow = lastbit^secondtolastbit;
  useoriginal = ~overflow;
  //creats which to use
  usemin = lastbit&overflow;
  usemax = secondtolastbit&overflow;
  //checks which one to use
  result = (min&usemin) + (max&usemax) + (result&useoriginal);
  return result;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  int negy = ~y + 1;
  //subtracts y from x
  int subtract = x + negy;
  int clear = 0x01;
  //1s if y>x
  int subresult = (subtract>>31);
  int xneg;
  int ypos;
  int diffsignsresult;
  int yneg;
  int xpos;
  int badsignsresult;
  int goodsignsresult;
  int result;
  //only works if y is not the minimum
  subresult = subresult&clear;

  //checks if x is pos and y is neg that way y min is not a problem
  xneg = (x>>31);
  xneg = xneg&clear;
  ypos = ~(y>>31);
  ypos = ypos&clear;
  diffsignsresult = xneg&ypos;

  yneg = (y>>31);
  xpos = ~(x>>31);
  badsignsresult = yneg&xpos;
  goodsignsresult = ~badsignsresult;

  result = diffsignsresult|subresult;
  result = result&goodsignsresult;
  
  return result;
}
/* 
 * 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int min = 0x30;
  int negativemin = ~min +1;
  int max = 0x39;
  int negativex = ~x+1;
  //subtracts the minimum value of ascii from x, if it is negative it is out of the range
  int tosmall = x+negativemin;
  int tobig;
  int result;
  tosmall = (tosmall>>31);
  //subtracts x from the max ascii value, if it is negative it is out of range
  tobig = max+negativex;
  tobig = (tobig>>31);

  result = tosmall|tobig;
  
  return !result;
}

/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
  //divides by 4 then multiplys by 3
  int divide = (x>>2);
  int add = divide+divide+divide;
  int firsttwobits = x<<30;
  int notlastbit;
  int addto;
  int useaddto;
  int result;
  int negnotlastbit;
  int firsttwomask = 3;
  //there are 4 posibal combinations of bits cut off by the shift 2
  //checks which case then adds the apropriet number to make the calculation corect
  firsttwobits = firsttwobits>>30;
  firsttwobits = firsttwobits&firsttwomask;
  notlastbit = x>>31;
  notlastbit = !notlastbit;
  negnotlastbit = ~notlastbit + 1;
  addto = firsttwobits + negnotlastbit;
  useaddto = !!firsttwobits;
  useaddto = useaddto<<31;
  useaddto = useaddto>>31;
  addto = addto&useaddto;
  result = add+addto;
  return result;
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  unsigned int ufshifted = uf<<1;
  unsigned int infinity = 0xff;
  unsigned int lastbitmask;
  unsigned int result;
  infinity = infinity<<24;
  //checks if it is nan
  if(ufshifted>infinity){
  return uf;
  }
  lastbitmask = 0x80;
  lastbitmask = lastbitmask<<24;
  //changes the last bit
  result = uf + lastbitmask;
  return result;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {  
  int isodd = 0;
  int m = x;
  int exponent = 0;
  int min;
  int negexpo;
  int posx;
  int E;
  unsigned int cutoff;
  unsigned int smalldigit;
  unsigned int half;
  int addto;
  unsigned int frac;
  int sign;
  unsigned int result;
  //checks if it is negitive then converts
  if(x<0){
    m = ~x +1;
    isodd = 1;
  }
  //checks if zero
  if(!x){
    return x;
  }
  min = 0x80;
  min = min<<24;
  //finds the first bit
  while(m>0){
    exponent = exponent+1;
    m = m<<1;
  }
  posx = m;
  m = m<<1;
  //creats the negative exponent
  negexpo = ~exponent +1;
  //subtracts it from the offset
  E = negexpo + 158;
  //positions the exponent
  E = E<<23;
  //checks rounding
  cutoff = posx<<24;
  smalldigit = posx<<23;
  smalldigit = smalldigit>>31;
  half = min;
  addto = 0;
  if(cutoff>half || (smalldigit&&!(cutoff<min))){
    addto = 1;
  }
  
  //gets the frac in the right place
  frac = m;
  frac = frac>>9;
  
  //gets the sign
  sign = isodd<<31;
  //puts them together
  result = sign + frac + E + addto;
  
  return result;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //doubles the float
  unsigned int ufshifted = uf<<1;
  unsigned int maxsize = 0xfe;
  unsigned int exponent;
  unsigned int sign;
  unsigned int answer;
  unsigned int addonetoexponent;
  unsigned int result;
  maxsize = maxsize<<24;
  //checks if it is over the max size and returns infinity
  if(ufshifted>maxsize){
    return uf;
  }
  exponent = ufshifted>>24;
  //checks if the exponent is zero
  if(!exponent){
    //returns the doubled one with the corect sign
    sign = uf>>31;
    sign = sign<<31;
    answer = sign+ufshifted;
    return answer;
  }
  //returns the value witht he corect sign
  addonetoexponent = 0x01;
  addonetoexponent = addonetoexponent<<23;
  result = uf + addonetoexponent;
  return result;
}
