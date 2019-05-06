;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname GUItemplate1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;    Type in (main 0) to start    ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(define MTS (empty-scene 600 400))  ;; creats the window


(define (main c)
  (big-bang c
    (on-tick tock) ;; adds 1 to c
    (to-draw render) ;; draws
    ;(stop-when ...)
   ; (on-mouse ...)
    ;(on-key ...)
    ))

(define (tock c)
  (+ c 5)
  
  )

(define (render c)
  (place-image (square 30 "solid" "red") 100 c MTS))