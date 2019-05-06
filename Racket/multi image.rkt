;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |multi image|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
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
(define-struct pos (x1 y1 x2 y2))
(define cs(make-pos 300 200 0 0))

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
  (place-image
   (square 30 "solid" "red") (pos-x1 c) (pos-y1 c)
   (place-image
    (square 30 "solid" "blue") (pos-x2 c) (pos-y2 c) MTS)))




(define (key-handler c key)  ; key is "the key pressed" ie for space " " for a "a"
  [cond [(key=? key "a") (make-pos (- (pos-x1 c) 5) (pos-y1 c) (pos-x2 c) (pos-y2 c))]
        [(key=? key "d") (make-pos (+ (pos-x1 c) 5) (pos-y1 c) (pos-x2 c) (pos-y2 c))]
        [(key=? key "w") (make-pos (pos-x1 c) (- (pos-y1 c) 5) (pos-x2 c) (pos-y2 c))]
        [(key=? key "s") (make-pos (pos-x1 c) (+ (pos-y1 c) 5) (pos-x2 c) (pos-y2 c))]
        [(key=? key "left") (make-pos (pos-x1 c) (pos-y1 c) (- (pos-x2 c) 5) (pos-y2 c))]
        [(key=? key "right") (make-pos (pos-x1 c) (pos-y1 c) (+ (pos-x2 c) 5) (pos-y2 c))]
        [(key=? key "up") (make-pos (pos-x1 c) (pos-y1 c) (pos-x2 c) (- (pos-y2 c) 5))]
        [(key=? key "down") (make-pos (pos-x1 c) (pos-y1 c) (pos-x2 c) (+ (pos-y2 c) 5))]
        [else c]
        ]
  )



(main cs)