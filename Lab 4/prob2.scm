; Taiki Tsukahara
; Team Members - Aaron Garcia, Taiki Tsukahara, Nhat Minh Dinh
; Lab 4 Due 11/24/2023
; Problem 2
#lang scheme
(define filter
  (lambda (f L)
    ; return list of those elements in L which pass through filter f
    (if (null? L) L ; if list L is empty?
        (if (f (car L)) ; checks first element of L
            (cons (car L) (filter f (cdr L))) ; makes new list by combining 2 parts.
            (filter f (cdr L)))))) ; recursive call

(define input '(3 9 5 8 2 4 7)) ; input value here
(display "From the list:(3 9 5 8 2 4 7)")
(newline)
(display "Number less than 5 are ")
(display (filter (lambda (num) (< num 5)) input)) ; Output: (3 2 4)
