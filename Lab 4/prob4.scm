; Taiki Tsukahara
; Team Members - Aaron Garcia, Taiki Tsukahara, Nhat Minh Dinh
; Lab 4 Due 11/24/2023
; Problem 4
#lang scheme

(define reverse
  (lambda (lst)
    (cond
      ((null? lst) '()) ; If list is empty = return an empty list
      (else (append (reverse (cdr lst)) (list (car lst)))))))
; Reverse the rest and append the first element at the end

(define display-reverse
  (lambda (lst)
    (display "(")
    (let loop ((lst lst))
      (cond
        ((null? lst) (display ")"))
        ((null? (cdr lst)) (display (car lst)) (display ")"))
        (else (display (car lst)) (display " ") (loop (cdr lst)))))))

(define myinput '(1 1 2 A 2 B 3 C)) ; input value here
(display "Reverse order of ")
(display myinput)
(display " is ")
(display-reverse (reverse myinput)) ; (1 1 2 A 2 B 3 C) = (C 3 B 2 A 2 1 1)
