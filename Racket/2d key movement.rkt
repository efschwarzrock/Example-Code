;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |2d key movement|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;    Type in (main cs) to start   ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(define MTS (empty-scene 600 400))  ;; creats the window
(define-struct pos (x y))
(define cs(make-pos 300 200))

(define (main c)
  (big-bang c
    ;
    ;(on-tick tock) ;; adds to c
    (to-draw render) ;; draws
    ;(stop-when ...)
    ; (on-mouse ...)
    (on-key key-handler)
    ))

;(define (tock c)
 ; (+ (pos-t cs) 1)
  
  ;)

(define (render c)
  (place-image (square 30 "solid" "red") (pos-x c) (pos-y c) MTS)
  )

(define (key-handler c key)  ; key is "the key pressed" ie for space " " for a "a"
  [cond [(key=? key "a") (make-pos (- (pos-x c) 5) (pos-y c))]
        [(key=? key "d") (make-pos (+ (pos-x c) 5) (pos-y c))]
        [(key=? key "w") (make-pos (pos-x c) (- (pos-y c) 5))]
        [(key=? key "s") (make-pos (pos-x c) (+ (pos-y c) 5))]
        [else c]
        ]
  )