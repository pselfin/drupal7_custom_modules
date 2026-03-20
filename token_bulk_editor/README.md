# Token Bulk Editor — массовое редактирование токенов для Drupal 7

Модуль добавляет единую страницу для редактирования всех кастомных токенов (модуль `token_custom`) в одном месте. Вместо того чтобы открывать каждый токен отдельно, можно изменить значения и форматы сразу всех токенов и сохранить одной кнопкой.

Модуль создан с помощью искусственного интеллекта [Claude](https://claude.ai) от Anthropic.

---

## Как работает

На странице отображается таблица всех кастомных токенов, сгруппированных по типу. Для каждого токена в строке показаны:

- **Название** — человекочитаемое имя токена
- **Токен** — машинное имя в формате `[тип:токен]`
- **Описание** — описание токена
- **Значение** — редактируемое текстовое поле
- **Формат** — выпадающий список форматов текста (plain_text, full_html и др.)
- **Ссылка** — переход на полную форму редактирования конкретного токена

Кнопка **«Сохранить все токены»** сохраняет изменения сразу для всех токенов на странице.

Дополнительно: при создании нового токена через стандартный интерфейс `token_custom` формат по умолчанию автоматически переключается на `plain_text`.

## Установка

1. Убедиться, что установлен и включён модуль `token_custom`
2. Скопировать папку `token_bulk_editor` в `sites/all/modules/custom/`
3. Включить модуль: `Администрирование → Модули` → найти «Token Bulk Editor»
4. При необходимости выдать права роли: `Администрирование → Пользователи → Права` → разрешение **«Bulk edit custom tokens»**

## Использование

Страница массового редактирования доступна по адресу:

`admin/structure/token-custom/token-bulk-editor`

Также открывается через вкладку **«Массовое редактирование»** на странице управления токенами (`admin/structure/token-custom`).

## Зависимости

- Drupal 7.x
- Модуль [`token_custom`](https://www.drupal.org/project/token_custom)

## Структура файлов

```
token_bulk_editor/
├── token_bulk_editor.info      # Мета-информация модуля
├── token_bulk_editor.module    # Хуки: permission, menu, form_alter
└── token_bulk_editor.admin.inc # Форма массового редактирования и обработчик сохранения
```

## Лицензия

GPLv2

---

&copy; Пётр Селфин — [selfin.pro](https://selfin.pro) | [pro-self.ru](https://pro-self.ru)

---
---

# Token Bulk Editor — Bulk Token Editing for Drupal 7

Adds a single admin page to edit all custom tokens (from the `token_custom` module) in one place. Instead of opening each token separately, you can update values and text formats for all tokens at once and save with a single button.

This module was built with the help of [Claude](https://claude.ai) AI by Anthropic.

---

## How it works

The page displays a table of all custom tokens grouped by type. Each row shows:

- **Name** — human-readable token name
- **Token** — machine name in `[type:token]` format
- **Description** — token description
- **Value** — editable textarea
- **Format** — text format dropdown (plain_text, full_html, etc.)
- **Link** — opens the individual token edit form

The **"Сохранить все токены" (Save all tokens)** button saves changes to all tokens on the page at once.

Additionally: when creating a new token via the standard `token_custom` interface, the text format defaults to `plain_text` automatically.

## Installation

1. Make sure the `token_custom` module is installed and enabled
2. Copy the `token_bulk_editor` folder to `sites/all/modules/custom/`
3. Enable the module at `Administration → Modules` → find "Token Bulk Editor"
4. If needed, grant the permission to a role: `Administration → Users → Permissions` → **"Bulk edit custom tokens"**

## Usage

The bulk editing page is available at:

`admin/structure/token-custom/token-bulk-editor`

It also appears as the **"Массовое редактирование"** tab on the token management page (`admin/structure/token-custom`).

## Dependencies

- Drupal 7.x
- [`token_custom`](https://www.drupal.org/project/token_custom) module

## File structure

```
token_bulk_editor/
├── token_bulk_editor.info      # Module metadata
├── token_bulk_editor.module    # Hooks: permission, menu, form_alter
└── token_bulk_editor.admin.inc # Bulk edit form and save handler
```

## License

GPLv2

---

&copy; Petr Selfin — [selfin.pro](https://selfin.pro) | [pro-self.ru](https://pro-self.ru)
