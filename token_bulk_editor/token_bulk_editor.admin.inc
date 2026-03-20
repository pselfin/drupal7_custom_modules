<?php

/**
 * @file
 * Admin page callbacks for token_bulk_editor.
 */

/**
 * Form builder: bulk token editor.
 */
function token_bulk_editor_form($form, &$form_state) {
  $tokens = token_custom_load_multiple();
  $types  = token_custom_type_load_multiple();

  if (empty($tokens)) {
    drupal_set_message(t('Нет кастомных токенов. <a href=@url>Создайте первый токен</a>.', array(
      '@url' => url('admin/structure/token-custom/add'),
    )), 'warning');
    return $form;
  }

  $formats = array();
  foreach (filter_formats() as $fid => $fmt) {
    $formats[$fid] = $fmt->name;
  }

  $by_type = array();
  foreach ($tokens as $machine_name => $token) {
    $by_type[$token->type][$machine_name] = $token;
  }

  $form['tokens'] = array('#tree' => TRUE);

  foreach ($by_type as $type_key => $type_tokens) {
    $type_label = isset($types[$type_key]) ? check_plain($types[$type_key]->name) : check_plain($type_key);

    $form['tokens'][$type_key]['_header'] = array(
      '#markup' => '<h3>' . $type_label . '</h3>',
    );

    $form['tokens'][$type_key]['_table_start'] = array(
      '#markup' => '<table class=sticky-enabled>'
        . '<thead><tr>'
        . '<th>' . t('Название') . '</th>'
        . '<th>' . t('Токен') . '</th>'
        . '<th>' . t('Описание') . '</th>'
        . '<th>' . t('Значение') . '</th>'
        . '<th>' . t('Формат') . '</th>'
        . '<th></th>'
        . '</tr></thead><tbody>',
    );

    foreach ($type_tokens as $machine_name => $token) {
      $edit_url = url('admin/structure/token-custom/' . $machine_name . '/edit');

      $form['tokens'][$type_key][$machine_name]['_row_start'] = array(
        '#markup' => '<tr>'
          . '<td>' . check_plain($token->name) . '</td>'
          . '<td><code>[' . check_plain($type_key) . ':' . check_plain($machine_name) . ']</code></td>'
          . '<td>' . check_plain($token->description) . '</td>'
          . '<td>',
      );

      $form['tokens'][$type_key][$machine_name]['content'] = array(
        '#type'          => 'textarea',
        '#default_value' => $token->content,
        '#rows'          => 2,
        '#resizable'     => FALSE,
        '#wysiwyg'       => FALSE,
        '#title'         => '',
        '#title_display' => 'invisible',
      );

      $form['tokens'][$type_key][$machine_name]['_sep'] = array(
        '#markup' => '</td><td>',
      );

      $form['tokens'][$type_key][$machine_name]['format'] = array(
        '#type'          => 'select',
        '#options'       => $formats,
        '#default_value' => isset($token->format) ? $token->format : 'plain_text',
        '#title'         => '',
        '#title_display' => 'invisible',
      );

      $form['tokens'][$type_key][$machine_name]['_row_end'] = array(
        '#markup' => '</td>'
          . '<td><a href= . \$edit_url . >' . t('Изменить') . '</a></td>'
          . '</tr>',
      );
    }

    $form['tokens'][$type_key]['_table_end'] = array(
      '#markup' => '</tbody></table>',
    );
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Сохранить все токены'),
  );

  $form['manage_link'] = array(
    '#markup' => '<p>' . l(t('Управление токенами (добавить / удалить)'), 'admin/structure/token-custom') . '</p>',
    '#weight' => 100,
  );

  return $form;
}

/**
 * Submit handler: save all tokens.
 */
function token_bulk_editor_form_submit($form, &$form_state) {
  $saved = 0;

  foreach ($form_state['values']['tokens'] as $type_key => $type_tokens) {
    foreach ($type_tokens as $machine_name => $values) {
      if (!is_array($values) || !isset($values['content'])) {
        continue;
      }
      $token = token_custom_load($machine_name);
      if (!$token) {
        continue;
      }
      $token->content = $values['content'];
      $token->format  = $values['format'];
      $token->is_new  = FALSE;

      if (token_custom_save($token)) {
        $saved++;
      }
      else {
        drupal_set_message(t('Ошибка при сохранении токена @name.', array('@name' => $machine_name)), 'error');
      }
    }
  }

  if ($saved) {
    drupal_set_message(t('Сохранено токенов: @count.', array('@count' => $saved)));
  }
}
