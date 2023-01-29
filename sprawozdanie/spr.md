---
title: "Badanie Zależności temperaturowej przewodnictwa elektrycznego metali i półprzewodników"
geometry: margin=2cm
header-includes: |
    \usepackage{polski}
    \usepackage[nosingleletter]{impnattypo}
    \usepackage{multicol}
    \usepackage{wrapfig}
    \usepackage{longtable}
---

\begin{vfill}
    \begin{raggedleft}
    IPpp sem. 3 \\*
    sekcja 6 \\*
    Piotr Świder \\*
    Artur Kuś \\*
    \end{raggedleft}
\end{vfill}

\newpage

# Wstęp

![układ pomiarowy:](/home/artqs01/Dane/MaterialyPOLSL/Fizyka/spr3/schemat.png)

### Przebieg ćwiczenia



# Zadanie 1

$$ \Delta U = 0.5\% U + 0.01\% 1000 [mV] $$

### Niepewność dla napięcia

\begin{longtable}{c|c|c|c|c|c}
\caption{Wyrażenie $\frac{ \Delta U}{ \sqrt{3} } [mV]$ dla każdego pomiaru}\tabularnewline
$u(U)[mV]$ & $U_1$ & $U_2$ & $U_3$ & $U_4$ & $U_5$ \\ \hline
& 0.4196427052 & 0.4201190308 & 0.4204759208 & 0.4205353731 & 0.4207136794
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(U)[mV]$ & $U_6$ & $U_7$ & $U_8$ & $U_9$ & $U_{10}$ \\ \hline
& 0.4209513036 & 0.4211294338 & 0.4214261501 & 0.4217226577 & 0.4220189569
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(U)[mV]$ & $U_{11}$ & $U_{12}$ & $U_{13}$ & $U_{14}$ & $U_{15}$ \\ \hline
& 0.4223150483 & 0.4226700841 & 0.4229657197 & 0.4232611487 & 0.4236744033
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(U)[mV]$ & $U_{16}$ & $U_{17}$ & $U_{18}$ & $U_{19}$ & $U_{20}$ \\ \hline
& 0.4239693385 & 0.4243229902 & 0.4247352116 & 0.4250294107 & 0.4254409477
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(U)[mV]$ & $U_{21}$ & $U_{22}$ & $U_{23}$ & $U_{24}$ & $U_{25}$ \\ \hline
& 0.425852087 & 0.4262041764 & 0.4266145802 & 0.4270245895 & 0.42749269
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(U)[mV]$ & $U_{26}$ & $U_{27}$ & $U_{28}$ & $U_{29}$ & $U_{30}$ \\ \hline
& 0.4279018579 & 0.4283106349 & 0.4287773315 & 0.4292435206 & 0.429709204
\end{longtable}

### Niepewność dla prądu

$$ \Delta I = \frac{ klasa \cdot zakres}{100} $$
$$ u(I) = \frac{ \Delta I}{ \sqrt{3} } $$
$$ u(I) = 0,00008660254038 [mA] $$

### Ostateczne wyniki

$$ I = 1.500000(87) [mA] $$

\begin{longtable}{c|c|c|c|c|c}
\caption{Ostateczne wyniki $U [mV]$ dla każdego pomiaru}\tabularnewline
$U[mV]$ & $U_1$ & $U_2$ & $U_3$ & $U_4$ & $U_5$ \\ \hline
& 152.20(42) & 153.00(42) & 153.60(42) & 153.70(42) & 154.00(42)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$U[mV]$ & $U_6$ & $U_7$ & $U_8$ & $U_9$ & $U_{10}$ \\ \hline
& 154.40(42) & 154.70(42) & 155.20(42) & 155.70(42) & 156.20(42)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$U[mV]$ & $U_{11}$ & $U_{12}$ & $U_{13}$ & $U_{14}$ & $U_{15}$ \\ \hline
& 156.70(42) & 157.30(42) & 157.80(42) & 158.30(42) & 159.00(42)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$U[mV]$ & $U_{16}$ & $U_{17}$ & $U_{18}$ & $U_{19}$ & $U_{20}$ \\ \hline
& 159.50(42) & 160.10(42) & 160.80(42) & 161.30(43) & 162.00(43)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$U[mV]$ & $U_{21}$ & $U_{22}$ & $U_{23}$ & $U_{24}$ & $U_{25}$ \\ \hline
& 162.70(43) & 163.30(43) & 164.00(43) & 164.70(43) & 165.50(43)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$U[mV]$ & $U_{26}$ & $U_{27}$ & $U_{28}$ & $U_{29}$ & $U_{30}$ \\ \hline
& 166.20(43) & 166.90(43) & 167.70(43) & 168.50(43) & 169.30(43)
\end{longtable}
# Zadanie 2

### Rezystancja wyliczona z prawa Ohma

\begin{longtable}{c|c|c|c|c|c}
\caption{Wyrażenie $R = \frac{U}{I}$ dla każdego pomiaru}\tabularnewline
$R[\Omega]$ & $R_1$ & $R_2$ & $R_3$ & $R_4$ & $R_5$ \\ \hline
& 101.4666667 & 102 & 102.4 & 102.4666667 & 102.6666667
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_6$ & $R_7$ & $R_8$ & $R_9$ & $R_{10}$ \\ \hline
& 102.9333333 & 103.1333333 & 103.4666667 & 103.8 & 104.1333333
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{11}$ & $R_{12}$ & $R_{13}$ & $R_{14}$ & $R_{15}$ \\ \hline
& 104.4666667 & 104.8666667 & 105.2 & 105.5333333 & 106
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{16}$ & $R_{17}$ & $R_{18}$ & $R_{19}$ & $R_{20}$ \\ \hline
& 106.3333333 & 106.7333333 & 107.2 & 107.5333333 & 108
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{21}$ & $R_{22}$ & $R_{23}$ & $R_{24}$ & $R_{25}$ \\ \hline
& 108.4666667 & 108.8666667 & 109.3333333 & 109.8 & 110.3333333
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{26}$ & $R_{27}$ & $R_{28}$ & $R_{29}$ & $R_{30}$ \\ \hline
& 110.8 & 111.2666667 & 111.8 & 112.3333333 & 112.8666667
\end{longtable}

### Niepewność wyliczenia rezystancji

$$ u(R) = \sqrt{ \sum_{i=1}^{k} \left( \frac{∂ R}{∂ x_i} \cdot u(x_i)\right)^2 } $$
$$ u(R) = \sqrt{ \left( \frac{1}{I} \cdot u(U)\right)^2 + \left( \frac{U}{I^2} \cdot u(I)\right)^2 } $$

\begin{longtable}{c|c|c|c|c|c}
\caption{Wyrażenie $u(R)$ dla każdego pomiaru}\tabularnewline
$u(R) [\Omega]$ & $R_1$ & $R_2$ & $R_3$ & $R_4$ & $R_5$ \\ \hline
& 0.2798231315 & 0.280141258 & 0.2803796182 & 0.2804193254 & 0.2805384136
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_6$ & $R_7$ & $R_8$ & $R_9$ & $R_{10}$ \\ \hline
& 0.2806971199 & 0.2808160914 & 0.2810142663 & 0.2812123028 & 0.2814102013
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_{11}$ & $R_{12}$ & $R_{13}$ & $R_{14}$ & $R_{15}$ \\ \hline
& 0.281607962 & 0.2818450935 & 0.2820425522 & 0.282239874 & 0.2825158953
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_{16}$ & $R_{17}$ & $R_{18}$ & $R_{19}$ & $R_{20}$ \\ \hline
& 0.28271289 & 0.2829491042 & 0.2832244409 & 0.2834209477 & 0.2836958309
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$ u(R)[\Omega]$ & $R_{21}$ & $R_{22}$ & $R_{23}$ & $R_{24}$ & $R_{25}$ \\ \hline
& 0.2839704504 & 0.2842056295 & 0.2844797617 & 0.2847536325 & 0.2850663087
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_{26}$ & $R_{27}$ & $R_{28}$ & $R_{29}$ & $R_{30}$ \\ \hline
& 0.285339622 & 0.2856126764 & 0.2859244223 & 0.2862358319 & 0.2865469065
\end{longtable}

### Ostateczny wynik rezystancji

\begin{longtable}{c|c|c|c|c|c}
\caption{Ostateczny wynik $R[\Omega]$ dla każdego pomiaru}\tabularnewline
$R[\Omega]$ & $R_1$ & $R_2$ & $R_3$ & $R_4$ & $R_5$ \\ \hline
& 101.47(28) & 102.00(28) & 102.40(28) & 102.47(28) & 102.67(28)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_6$ & $R_7$ & $R_8$ & $R_9$ & $R_{10}$ \\ \hline
& 102.93(28) & 103.13(28) & 103.47(28) & 103.80(28) & 104.13(28)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{11}$ & $R_{12}$ & $R_{13}$ & $R_{14}$ & $R_{15}$ \\ \hline
& 104.47(28) & 104.87(28) & 105.20(28) & 105.53(28) & 106.00(28)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{16}$ & $R_{17}$ & $R_{18}$ & $R_{19}$ & $R_{20}$ \\ \hline
& 106.33(28) & 106.73(28) & 107.2(28) & 107.53(28) & 108.00(28)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{21}$ & $R_{22}$ & $R_{23}$ & $R_{24}$ & $R_{25}$ \\ \hline
& 108.47(28) & 108.87(28) & 109.33(28) & 109.80(29) & 110.33(29)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{26}$ & $R_{27}$ & $R_{28}$ & $R_{29}$ & $R_{30}$ \\ \hline
& 110.80(29) & 111.27(29) & 111.80(29) & 112.33(29) & 112.87(29)
\end{longtable}

# Zadanie 3

$$ a = 0.1936925207 $$
$$ b = 96.27042255 $$
$$ u(a) = 0.003986034354 $$
$$ u(b) = 0.2222777548 $$

![Zależność $R(T)$ z naniesioną prostą aproksymacyjną](/home/artqs01/Dane/MaterialyPOLSL/Fizyka/spr3/wykres_R.png)

\newpage

# Zadanie 4

## Wyznaczenie $R_0$ i $\alpha$

$$ R_M = R_0(1 + \alpha T) $$
$$ R_M = R_0 + \alpha R_0 T $$

$$ a = \alpha \cdot R_0 $$
$$ b = R_0 $$

$$ R_M = aT + b $$
$$ R_0 = 0a + b $$
$$ R_0 = 96.48967 [\Omega] $$
$$ u(R_0) = 0.2865469065 $$

$$ \alpha = \frac{a}{R_0} $$
$$ \alpha =  \frac{0.1936925207}{96.48967} $$
$$ \alpha = 0.002007391265 $$

$$ u(\alpha) = \sqrt{ \left( \frac{1}{R_0} \cdot u(a)\right)^2 + \left( \frac{a}{R_0^2} \cdot u(R_0)\right)^2 } $$
$$ u(\alpha) = \sqrt{ \left( \frac{1}{96.48967} \cdot 0.003986034354\right)^2 + \left( \frac{0.1936925207}{96.27042255^2} \cdot 0.2865469065\right)^2 } $$
$$ u(\alpha) = 0,00004183539642 $$

### Ostateczny wynik

$$ R_0 = 96.49(29) [\Omega] $$
$$ \alpha = 0.002007(42) [\Omega] $$

# Zadanie 5

$$ \Delta R = 0.005 \cdot R_p + 5 \cdot 0.001 $$
$$ u(R) = \frac{ \Delta R }{ \sqrt{3} } $$

\begin{longtable}{c|c|c|c|c|c}
\caption{Wyrażenie $u(R)$ dla każdego pomiaru}\tabularnewline
$u(R) [\Omega]$ & $R_1$ & $R_2$ & $R_3$ & $R_4$ & $R_5$ \\ \hline
& 0.006873354955 & 0.006746337895 & 0.006636641344 & 0.00660488708 & 0.006564472561
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_6$ & $R_7$ & $R_8$ & $R_9$ & $R_{10}$ \\ \hline
& 0.006492303777 & 0.006420134993 & 0.006333532453 & 0.00624115641 & 0.006140120113
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_{11}$ & $R_{12}$ & $R_{13}$ & $R_{14}$ & $R_{15}$ \\ \hline
& 0.006044857318 & 0.005938047519 & 0.005828350967 & 0.005718654416 & 0.005611844617
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_{16}$ & $R_{17}$ & $R_{18}$ & $R_{19}$ & $R_{20}$ \\ \hline
& 0.005502148065 & 0.005389564763 & 0.005279868212 & 0.005170171661 & 0.005066248612
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$ u(R)[\Omega]$ & $R_{21}$ & $R_{22}$ & $R_{23}$ & $R_{24}$ & $R_{25}$ \\ \hline
& 0.004959438812 & 0.004858402515 & 0.004757366218 & 0.004664990175 & 0.004569727381
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$u(R)[\Omega]$ & $R_{26}$ & $R_{27}$ & $R_{28}$ & $R_{29}$ & $R_{30}$ \\ \hline
& 0.00448312484 & 0.004399409051 & 0.004307033008 & 0.004220430468 & 0.004142488181
\end{longtable}

### Ostateczny wynik rezystancji $R_p$

\begin{longtable}{c|c|c|c|c|c}
\caption{Ostateczny wynik $R[\Omega]$ dla każdego pomiaru}\tabularnewline
$R[\Omega]$ & $R_1$ & $R_2$ & $R_3$ & $R_4$ & $R_5$ \\ \hline
& 1.3810(69) & 1.3370(67) & 1.2990(66) & 1.2880(66) & 1.2740(66)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_6$ & $R_7$ & $R_8$ & $R_9$ & $R_{10}$ \\ \hline
& 1.2490(65) & 1.2240(64) & 1.1940(63) & 1.1620(62) & 1.1270(61)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{11}$ & $R_{12}$ & $R_{13}$ & $R_{14}$ & $R_{15}$ \\ \hline
& 1.0940(60) & 1.0570(59) & 1.0190(58) & 0.9810(57) & 0.9440(56)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{16}$ & $R_{17}$ & $R_{18}$ & $R_{19}$ & $R_{20}$ \\ \hline
& 0.9060(55) & 0.8670(54) & 0.8290(53) & 0.7910(52) & 0.7550(51)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{21}$ & $R_{22}$ & $R_{23}$ & $R_{24}$ & $R_{25}$ \\ \hline
& 0.7180(50) & 0.6830(49) & 0.6480(48) & 0.6160(47) & 0.5830(46)
\end{longtable}

\begin{longtable}{c|c|c|c|c|c}
$R[\Omega]$ & $R_{26}$ & $R_{27}$ & $R_{28}$ & $R_{29}$ & $R_{30}$ \\ \hline
& 0.5530(45) & 0.5240(44) & 0.4920(43) & 0.4620(42) & 0.4350(41)
\end{longtable}

\newpage

# Zadanie 6

![Zależność $R(T)$](/home/artqs01/Dane/MaterialyPOLSL/Fizyka/spr3/wykres6.png)

# Zadanie 7

$$ a = 38.41456964 $$
$$ b = 5.942967898 $$
$$ u(a) = 3.806682349 $$
$$ u(b) = 0.0868558005 $$

\newpage

![Zależność $ln(R)$ od $1/T$](/home/artqs01/Dane/MaterialyPOLSL/Fizyka/spr3/wykres7.png)

# Zadanie 8

$$ ln(R_p) = \frac{E_a}{2kT} + ln(R_0) $$
$$ a = \frac{E_a}{2k} $$
$$ E_a = \frac{a}{2k} $$

$$ k = 8.617333262 \cdot 10^{-5} \left[ \frac{eV}{K} \right] $$
$$ a = 38.41456964 $$

$$ E_a = 445782.5695 [eV] $$

### Niepewnośc wyzaczenia $E_a$

$$ u(E_a) = 44174.71431 [eV] $$

### Ostateczny wynik $E_a$
$$ E_a = 4.45(44) \cdot 10^5 [eV] $$

# Wnioski

W zadaniu 6 na wykresie charakterystyka z bliżej nieokreślonych przyczyn bardziej przypomina linię, niż $e^x$. Niepewności nie wskazuja na błąd przyrządów, więc mogło dojść do niepoprawnie zczytanych wyników przez nas.














