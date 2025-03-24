fun range l r = if l > r then [] else l :: range (l + 1) r;

fun hasMod l el = foldr (fn (a, b) => if el mod a = 0 then true else b) false l;

val ans = foldr (fn (a, b) => if hasMod [3, 5] a then b + a else b) 0 (range 1 999);