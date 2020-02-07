# ft_printf
Re-creation of <stdio.h> printf function.

ft_printf use the "print as you go method". <br /> 
This means if it does not detect a '%' with a specifier,
It prints th current value in **format. (defined in (const char **fmt, ...))

## Ft_printf can handle the following specifiers:

**%s** - Print a regular Ascii string. <br />
**%S** - Print wide string or Unicode string. <br />
**%c** - Print regular Ascii character. <br />
**%C** - Print wide character or Unicode character. <br />
**%d** - Print decimal int. <br />
**%D** - Print long int. <br />
**%u** - Print unsigned int. <br />
**%U** - Print unsigned long. <br />
**%x** - Print hexideciaml value of passed argument. (Default Prefex '0x') <br />
**%X** - Print hexidecimal vlaue of passed argument. (Prefex with '0X') <br />
**%i** - Print integer. <br />
**%p** - Print passed pointer address. <br />

## The following Flags are compatable with ft_print:

**'+'** - Preceed Value with a '+' sign. <br />
**'-'** - Preceed Vlaue with a '-' sign. <br />
**'#'** - Various uses: <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%#o (Octal) 0 prefix inserted. <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%#x (Hex)   0x prefix added to non-zero values. <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%#X (Hex)   0X prefix added to non-zero values. <br />
**'0'** - Zero pad value with 0's up tp precsion or field width. <br />
**'  '** - White space pad value, works with left & right justified. <br />

## The following length modifiers are compatible with ft_printf:

View relative table for more informationon these modifiers:
[C++ - Reference](http://www.cplusplus.com/reference/cstdio/printf/) <br />
**l**  <br />
**ll** <br />
**h**  <br />
**hh** <br />
**z**  <br />
**j**  <br />
