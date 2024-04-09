; Taiki Tsukahara
; Team Members - Aaron Garcia, Taiki Tsukahara, Nhat Minh Dinh
; Lab 4 Due 11/24/2023
; Problem 3
#lang scheme
(define rotations
  (lambda (L)
    (letrec
        ((helper
          (lambda (Ls A B)
            (if (null? B)
                Ls
                (helper (append Ls (list (append B A)))
                        (append A (list (car B)))
                        (cdr B))))))
      (helper '() '() L))))
(display "Rotations of (a b c d e):")
(newline)
(display (rotations '(a b c d e)))
; Output: ((a b c d e) (b c d e a) (c d e a b) (d e a b c) (e a b c d))