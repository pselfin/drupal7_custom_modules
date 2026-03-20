# Custom Cookies — модуль согласия с cookie для Drupal 7

Модуль отображает всплывающую плашку согласия с cookie для соответствия требованиям GDPR. Текст, ссылка на политику конфиденциальности и оформление кнопки настраиваются через административный интерфейс без правки кода.

Модуль создан с помощью искусственного интеллекта [Claude](https://claude.ai) от Anthropic.

---

## Как работает

При загрузке страницы JavaScript проверяет наличие cookie `cookies_policy`. Если cookie нет — плашка видна. При нажатии кнопки cookie устанавливается на заданный срок, и плашка скрывается добавлением класса `cookie-hidden`. При повторных визитах плашка не показывается.

Если JavaScript недоступен — плашка остаётся видимой (корректная деградация).

## Установка

1. Скопировать папку `custom_coockies` в `sites/all/modules/custom/`
2. Включить модуль: `Администрирование → Модули`
3. Разместить блок **«Cookie Consent Popup»** в нужном регионе: `Администрирование → Структура → Блоки`

## Настройки

Страница настроек: `admin/config/system/site-information/custom-coockies`
(вкладка «Cookie уведомление» на странице «Информация о сайте»)

| Настройка | По умолчанию |
|---|---|
| Текст уведомления | «Продолжая пользоваться сайтом…» |
| URL политики конфиденциальности | `/privacy-policy` |
| Текст ссылки | «политикой конфиденциальности» |
| Текст кнопки | `Понятно` |
| Цвет фона кнопки (HEX) | `#5543bd` |
| Цвет рамки кнопки (HEX) | `#3d3185` |
| Срок хранения cookie (дней) | `90` |

В тексте уведомления используются плейсхолдеры:
- `[link]` — подставляется URL политики конфиденциальности
- `[link_text]` — подставляется текст ссылки

## Структура файлов

```
custom_coockies/
├── custom_cookies.info       # Мета-информация модуля
├── custom_cookies.module     # Хуки Drupal (menu, block_info, block_view)
├── custom_cookies.admin.inc  # Форма настроек (system_settings_form)
├── custom_cookies.css        # Стили плашки
└── custom_cookies.js         # Логика показа/скрытия, установка cookie
```

## Требования

- Drupal 7.x

## Лицензия

GPLv2

---

&copy; Пётр Селфин — [selfin.pro](https://selfin.pro) | [pro-self.ru](https://pro-self.ru)

---
---

# Custom Cookies — GDPR Cookie Consent Module for Drupal 7

Displays a cookie consent popup to comply with GDPR requirements. The notification text, privacy policy link, and button appearance are all configurable through the admin interface without editing code.

This module was built with the help of [Claude](https://claude.ai) AI by Anthropic.

---

## How it works

On page load, JavaScript checks for the `cookies_policy` cookie. If absent, the popup is visible. When the user clicks the button, the cookie is set for the configured number of days, and the popup is hidden by adding the `cookie-hidden` CSS class. On subsequent visits the popup is not shown.

If JavaScript is unavailable, the popup remains visible (graceful degradation).

## Installation

1. Copy the `custom_coockies` folder to `sites/all/modules/custom/`
2. Enable the module at `Administration → Modules`
3. Place the **"Cookie Consent Popup"** block in the desired region: `Administration → Structure → Blocks`

## Settings

Settings page: `admin/config/system/site-information/custom-coockies`
(the "Cookie уведомление" tab on the Site Information page)

| Setting | Default |
|---|---|
| Notification text | «Продолжая пользоваться сайтом…» |
| Privacy policy URL | `/privacy-policy` |
| Link text | «политикой конфиденциальности» |
| Button text | `Понятно` |
| Button background color (HEX) | `#5543bd` |
| Button border color (HEX) | `#3d3185` |
| Cookie lifetime (days) | `90` |

Placeholders available in the notification text:
- `[link]` — replaced with the privacy policy URL
- `[link_text]` — replaced with the link text

## File structure

```
custom_coockies/
├── custom_cookies.info       # Module metadata
├── custom_cookies.module     # Drupal hooks (menu, block_info, block_view)
├── custom_cookies.admin.inc  # Settings form (system_settings_form)
├── custom_cookies.css        # Popup styles
└── custom_cookies.js         # Show/hide logic, cookie handling
```

## Requirements

- Drupal 7.x

## License

GPLv2

---

&copy; Petr Selfin — [selfin.pro](https://selfin.pro) | [pro-self.ru](https://pro-self.ru)
