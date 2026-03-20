<?php

/**
 * @file
 * Страница настроек модуля Custom Cookies.
 */

/**
 * Форма настроек.
 */
function custom_cookies_settings_form($form, &$form_state) {

  $form['text'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Текст уведомления'),
    '#collapsible' => FALSE,
  );

  $form['text']['custom_cookies_text'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Текст уведомления'),
    '#description'   => t('Используйте <code>[link]</code> для URL и <code>[link_text]</code> для текста ссылки политики конфиденциальности.'),
    '#default_value' => variable_get('custom_cookies_text', 'Продолжая пользоваться сайтом, вы соглашаетесь на обработку файлов cookie и других пользовательских данных в соответствии с <a href=[link] target=_blank>[link_text]</a>. Заблокировать использование cookies сайтом можно в настройках браузера.'),
    '#rows'          => 4,
  );

  $form['text']['custom_cookies_link'] = array(
    '#type'          => 'textfield',
    '#title'         => t('URL политики конфиденциальности'),
    '#default_value' => variable_get('custom_cookies_link', '/privacy-policy'),
    '#size'          => 60,
  );

  $form['text']['custom_cookies_link_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Текст ссылки'),
    '#default_value' => variable_get('custom_cookies_link_text', 'политикой конфиденциальности'),
    '#size'          => 40,
  );

  $form['button'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Кнопка'),
    '#collapsible' => FALSE,
  );

  $form['button']['custom_cookies_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Текст кнопки'),
    '#default_value' => variable_get('custom_cookies_button_text', 'Понятно'),
    '#size'          => 30,
    '#required'      => TRUE,
  );

  $form['button']['custom_cookies_button_color'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Цвет кнопки (фон)'),
    '#description'   => t('HEX-цвет, например <code>#5543bd</code>'),
    '#default_value' => variable_get('custom_cookies_button_color', '#5543bd'),
    '#size'          => 10,
    '#required'      => TRUE,
  );

  $form['button']['custom_cookies_button_border_color'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Цвет рамки кнопки'),
    '#description'   => t('HEX-цвет, например <code>#3d3185</code>'),
    '#default_value' => variable_get('custom_cookies_button_border_color', '#3d3185'),
    '#size'          => 10,
  );

  $form['cookie'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Cookie'),
    '#collapsible' => FALSE,
  );

  $form['cookie']['custom_cookies_cookie_days'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Срок хранения cookie (дней)'),
    '#description'   => t('Сколько дней помнить согласие пользователя.'),
    '#default_value' => variable_get('custom_cookies_cookie_days', 90),
    '#size'          => 5,
    '#required'      => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  return system_settings_form($form);
}
