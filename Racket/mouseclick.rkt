;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname mouseclick) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
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
    ; (on-tick tock) ;; adds to c
    (to-draw render) ;; draws
    ;(stop-when ...)
    (on-mouse click)
    ;(on-key key-handler)
    ))

;;(define (tock c)
;;(+ c 5)
  
;)

(define (render c)
  (if (> c 0)
  (place-image (square 30 "solid" "red") 100 100 MTS)
  (place-image (square 30 "solid" "blue") 100 100 MTS))
  )

;(define (key-handler c key)  ; key is "the key pressed" ie for space " " for a "a"
; ...
; )

(define (click c mx my evnt)
  [cond [(and (mouse=? evnt "button-down") (> mx 85) (< mx 115) (> my 85) (< my 115)) (* -1 c)]
        [else c]])


(main 1)