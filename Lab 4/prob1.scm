; Taiki Tsukahara
; Team Members - Aaron Garcia, Taiki Tsukahara, Nhat Minh Dinh
; Lab 4 Due 11/24/2023
; Problem 1
#lang scheme
(define log2
  (lambda (n) ;input n
    (letrec
        ((helper
          (lambda (n acc)
            (if (= n 1) ; if input is 1
                acc ; return the result
                (helper (quotient (+ n 1) 2) (+ acc 1)))))) ; recursive call
      
      (helper n 0)))) ; initial values

(display "Log base 2 of 4 is ")
(display (log2 4)) ; what is the log base 2 of 4 = 2
