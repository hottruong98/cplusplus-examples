>***Remainder of remainder divided by n:***
>
>$(a\%n)\%n = a\%n$

>***Remainder of sum divided by n:***
>
>$(a+b+c+d)\%n$ 
>
>$= (a\%n+b\%n+c\%n+d\%n)\%n$
>
>$= (a+(b\%n+c\%n+d\%n)\%n)\%n$
>
>$= (a+(b+(c\%n+d\%n)\%n)\%n)\%n$
>
>$= (a+(b+(c+d)\%n)\%n)\%n$

>***Remainder of product divided by n:***
>
>$(abcd)\%n$
>
>$= (a\%n.b\%n.c\%n.d\%n)\%n$
>
>$= (a.(b\%n.c\%n.d\%n)\%n)\%n$
>
>$= (a.(b.(c\%n.d\%n)\%n)\%n)\%n$
>
>$= (a.(b.(c.d)\%n)\%n)\%n$

>
>$(a.b.c + d.e.f + g.h.i)\%n$
>
>$= [(a.b.c)\%n + (d.e.f)\%n + (g.h.i)\%n]\%n$
>
>$= [(a.(b.c)\%n)\%n + (d.(e.f)\%n)\%n + (g.(h.i)\%n)\%n]\%n$
>
>$= [(a.(b.c)\%n)\%n + ((d.(e.f)\%n) + (g.(h.i)\%n))\%n]\%n$
>

