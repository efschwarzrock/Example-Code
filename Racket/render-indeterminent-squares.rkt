;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname render-indeterminent-squares) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;    Type in (main 0) to start    ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define w 600)
(define h 400)
(define MTS (empty-scene w h))  ;; creats the window
(define WS empty)
(define-struct sq(sh pos-x pos-y))
(define sr (make-sq (square 30 "solid" "red") 50 50))

(define (main c)
  (big-bang c
    ;
    ;(on-tick tock) ;; adds to c
    (to-draw render) ;; draws
    ;(stop-when ...)
    (on-mouse mouse-click)
    ))

(define (mouse-click c mx my event)
  (if (string=? event "button-down")
       (cons (make-sq (square 30 "solid" "red") mx my) c)
       c))

(define (render c)
  (if (empty? c)
      MTS
      (place-image
       (sq-sh (first c)) (sq-pos-x (first c)) (sq-pos-y (first c))
       (render (rest c)))))






(main WS)