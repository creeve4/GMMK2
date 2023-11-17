RGB_MATRIX_EFFECT(mine)
RGB_MATRIX_EFFECT(off)

//Standard colors
#define BLUE		0, 82, 204
#define VIOLET		140, 0, 255
#define PINK		230, 0, 180
#define RED			255, 0, 0
#define ESC			140, 0, 0
#define ORANGE		255, 40, 0
#define YELLOW		200, 150, 0
#define GREEN		0, 190, 20
#define GREY		100, 100, 100
#define WHITE		220, 220, 220
#define OFF			0, 0, 0


// On
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool mine(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (uint8_t i = led_min; i < 99; i++) {
    rgb_matrix_set_color(i, BLUE);
  } 
  
  for (uint8_t i = 99; i < 119; i++) {
    rgb_matrix_set_color(i, OFF);			//Sides
  } 
  
  return rgb_matrix_check_finished_leds(led_max);
}


// Off
static bool off(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, OFF);
  } 
  
  return rgb_matrix_check_finished_leds(led_max);
}

#endif