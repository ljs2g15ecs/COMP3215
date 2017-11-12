#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* PORTA18 (number 6), RGB_B */
#define BOARD_INITPINS_RGB_B_GPIO                                          GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_INITPINS_RGB_B_PORT                                          PORTA   /*!< PORT device name: PORTA */
#define BOARD_INITPINS_RGB_B_GPIO_PIN                                        18U   /*!< PORTA pin index: 18 */
#define BOARD_INITPINS_RGB_B_PIN_NAME                                      PTA18   /*!< Pin name */
#define BOARD_INITPINS_RGB_B_LABEL                                       "RGB_B"   /*!< Label */
#define BOARD_INITPINS_RGB_B_NAME                                        "RGB_B"   /*!< Identifier name */

/* PORTA19 (number 7), RGB_G */
#define BOARD_INITPINS_RGB_G_GPIO                                          GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_INITPINS_RGB_G_PORT                                          PORTA   /*!< PORT device name: PORTA */
#define BOARD_INITPINS_RGB_G_GPIO_PIN                                        19U   /*!< PORTA pin index: 19 */
#define BOARD_INITPINS_RGB_G_PIN_NAME                                      PTA19   /*!< Pin name */
#define BOARD_INITPINS_RGB_G_LABEL                                       "RGB_G"   /*!< Label */
#define BOARD_INITPINS_RGB_G_NAME                                        "RGB_G"   /*!< Identifier name */

/* PORTC1 (number 37), RGB_R */
#define BOARD_INITPINS_RGB_R_GPIO                                          GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INITPINS_RGB_R_PORT                                          PORTC   /*!< PORT device name: PORTC */
#define BOARD_INITPINS_RGB_R_GPIO_PIN                                         1U   /*!< PORTC pin index: 1 */
#define BOARD_INITPINS_RGB_R_PIN_NAME                                       PTC1   /*!< Pin name */
#define BOARD_INITPINS_RGB_R_LABEL                                       "RGB_R"   /*!< Label */
#define BOARD_INITPINS_RGB_R_NAME                                        "RGB_R"   /*!< Identifier name */

/* PORTB0 (number 16), LED_R */
#define BOARD_INITPINS_LED_R_GPIO                                          GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_INITPINS_LED_R_PORT                                          PORTB   /*!< PORT device name: PORTB */
#define BOARD_INITPINS_LED_R_GPIO_PIN                                         0U   /*!< PORTB pin index: 0 */
#define BOARD_INITPINS_LED_R_PIN_NAME                                       PTB0   /*!< Pin name */
#define BOARD_INITPINS_LED_R_LABEL                                       "LED_R"   /*!< Label */
#define BOARD_INITPINS_LED_R_NAME                                        "LED_R"   /*!< Identifier name */

/* PORTC6 (number 42), RX */
#define BOARD_INITPINS_RX_PERIPHERAL                                     LPUART0   /*!< Device name: LPUART0 */
#define BOARD_INITPINS_RX_SIGNAL                                              RX   /*!< LPUART0 signal: RX */
#define BOARD_INITPINS_RX_PIN_NAME                                      UART0_RX   /*!< Pin name */
#define BOARD_INITPINS_RX_LABEL                                             "RX"   /*!< Label */
#define BOARD_INITPINS_RX_NAME                                              "RX"   /*!< Identifier name */

/* PORTC7 (number 43), TX */
#define BOARD_INITPINS_TX_PERIPHERAL                                     LPUART0   /*!< Device name: LPUART0 */
#define BOARD_INITPINS_TX_SIGNAL                                              TX   /*!< LPUART0 signal: TX */
#define BOARD_INITPINS_TX_PIN_NAME                                      UART0_TX   /*!< Pin name */
#define BOARD_INITPINS_TX_LABEL                                             "TX"   /*!< Label */
#define BOARD_INITPINS_TX_NAME                                              "TX"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
