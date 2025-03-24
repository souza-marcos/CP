(* Summation of all primes below two million *)

(* Simple and idiomatic but infeasible  *)
fun range l r = if l > r then [] else l :: range (l + 1) r;

fun primes n = 
  let
    val ini = range 2 n
    fun sieve [] = []
      | sieve (p :: xs) = p :: sieve (List.filter (fn x => x mod p <> 0) xs)
  in 
    sieve ini
  end;

(* Testing lazy lists => it's awesome but not resolve the problem of complexity *)
datatype 'a stream = Cons of 'a * (unit -> 'a stream)| Nil;

fun primesStream n = 
  let
    fun streamFilter f Nil = Nil
      | streamFilter f (Cons (x, xs)) = 
          if f x then Cons (x, fn () => streamFilter f (xs ()))
          else streamFilter f (xs ())

    fun rangeStream l r = if l > r then Nil else Cons (l, fn() => rangeStream (l+1) r)

    fun sieve Nil = Nil
      | sieve (Cons (p, xs)) = Cons (p, fn() => sieve (streamFilter (fn x => x mod p <> 0) (xs ())));
    
  in
    sieve (rangeStream 2 n)
  end;


fun toList Nil = []
  | toList (Cons (x, xs)) = x :: toList (xs ())

(* Iterative but faster *)
fun sieveIter n =
  let
    val isPrime = Array.tabulate (IntInf.toInt (n + 1), fn x => if x < 2 then false else true)

    fun markMultiples p = 
      if IntInf.*(p, p) > n then ()
      else 
        if Array.sub (isPrime, IntInf.toInt p) then 
          let
            fun mark i = 
              if i > (IntInf.toInt n) then () 
              else (Array.update (isPrime, i, false); mark (i + IntInf.toInt p))
          in
            mark (IntInf.toInt (IntInf.*(p, p))); 
            markMultiples (IntInf.+(p, IntInf.fromInt 1))
          end
        else markMultiples (IntInf.+(p, IntInf.fromInt 1))
  
    fun collectPrimes i acc = 
      if i > IntInf.toInt n then rev acc
      else 
        if Array.sub (isPrime, i) 
          then collectPrimes (i + 1) (IntInf.fromInt i :: acc)
        else collectPrimes (i + 1) acc 
  in
    markMultiples (IntInf.fromInt 2);
    collectPrimes 2 []
  end;

(* Timing the function *)
val startTime = Time.now();
val sumPrimes = foldl IntInf.+ (IntInf.fromInt 0) (sieveIter (IntInf.fromInt 2000000));
val endTime = Time.now();
val duration = Time.- (endTime, startTime);
val _ = print ("Sum of primes below 2,000,000: " ^ IntInf.toString sumPrimes ^ "\n");
val _ = print ("Time taken: " ^ Time.toString duration ^ " seconds\n");