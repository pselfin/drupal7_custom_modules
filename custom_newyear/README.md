# Custom New Year — новогоднее оформление для Drupal 7

Модуль добавляет на сайт два независимых новогодних эффекта: анимированную гирлянду из цветных лампочек и падающий снег. Оба эффекта управляются через административную панель, каждый включается отдельно.

Модуль создан с помощью искусственного интеллекта [Claude](https://claude.ai) от Anthropic.

---

## Возможности

- **Гирлянда** — 40 анимированных лампочек (циан, зелёный, пурпурный) с рандомизированным миганием на CSS-анимациях (`@keyframes`). Реализована как Drupal-блок, размещается в любом регионе темы.
- **Снег** — падающие снежинки на JavaScript. Количество, размер, скорость и до трёх цветов настраиваются в админке. JS генерируется динамически на основе сохранённых настроек.

## Установка

1. Скопировать папку `custom_newyear` в `sites/all/modules/custom/`
2. Включить модуль: `Администрирование → Модули` → найти «Custom New Year»
3. Открыть настройки: `Администрирование → Конфигурация → Пользовательский интерфейс → Custom New Year Settings`

## Настройки

### Основные

| Настройка | По умолчанию | Описание |
|---|---|---|
| Enable Christmas Lightrope | выкл. | Включить гирлянду |
| Enable Snow Effect | выкл. | Включить снег |

### Снег

| Настройка | По умолчанию | Рекомендуемый диапазон |
|---|---|---|
| Количество снежинок | `50` | 20–100 |
| Максимальный размер (px) | `40` | 20–60 |
| Скорость падения | `0.7` | 0.3–2.0 |
| Основной цвет | `#fff` | любой CSS-цвет |
| Дополнительный цвет 2 | — | необязательно |
| Дополнительный цвет 3 | — | необязательно |

Если задано несколько цветов, они распределяются по снежинкам случайным образом. Предпросмотр цветов доступен прямо на странице настроек.

### Гирлянда — оформление

| Настройка | По умолчанию | Описание |
|---|---|---|
| Цвет фона контейнера | — | CSS-цвет или `transparent` |
| Отступ сверху (px) | `-15` | отрицательные значения — сдвиг вверх |
| Отступ снизу (px) | `0` | |
| Произвольный CSS | — | дополнительные стили контейнера |

### Размещение гирлянды

Гирлянда реализована как блок **«Christmas Lightrope»**. После включения в настройках необходимо разместить блок в нужном регионе:

`Администрирование → Структура → Блоки` → найти «Christmas Lightrope» → перетащить в регион → сохранить.

Рекомендуемые регионы: **Header**, **Page top** или область над контентом.

## Структура файлов

```
custom_newyear/
├── custom_newyear.info       # Мета-информация модуля
├── custom_newyear.module     # Хуки: menu, permission, init, uninstall; генерация JS снега
├── custom_newyear.admin.inc  # Форма настроек с предпросмотром
├── custom_newyear.block.inc  # Реализация блока гирлянды (block_info, block_view)
├── css/
│   ├── styles.scss           # Точка входа SCSS
│   ├── _variables.scss       # Переменные (цвета лампочек, размеры)
│   ├── _mixins.scss          # Миксины
│   ├── _theme-overrides.scss # Переопределения для тем
│   ├── components/
│   │   └── _lightrope.scss   # Стили гирлянды
│   └── lightrope.css         # Скомпилированный CSS (подключается Drupal)
├── js/
│   └── snow-fall.js          # Базовый файл снега (не подключается, используется как справочник)
└── SCSS_BUILD_PROCESS.md     # Инструкция по сборке SCSS
```

## Сборка CSS из SCSS

```bash
# Установить Sass (один раз)
npm install -g sass

# Скомпилировать
sass css/styles.scss css/lightrope.css --style compressed

# Следить за изменениями
sass css/styles.scss css/lightrope.css --watch
```

После сохранения настроек в админке кэш CSS и JS очищается автоматически.

## Удаление

При деинсталляции модуль удаляет все свои переменные из базы данных через `hook_uninstall`.

## Требования

- Drupal 7.x
- Для пересборки CSS: Node.js + Sass

## Лицензия

GPLv2

---

&copy; Пётр Селфин — [selfin.pro](https://selfin.pro) | [pro-self.ru](https://pro-self.ru)

---
---

# Custom New Year — Holiday Decoration Module for Drupal 7

Adds two independent holiday effects to your site: an animated Christmas lightrope with colored bulbs and a falling snow animation. Both effects are managed through the admin panel and toggled independently.

This module was built with the help of [Claude](https://claude.ai) AI by Anthropic.

---

## Features

- **Lightrope** — 40 animated light bulbs (cyan, green, magenta) with randomized blinking via CSS `@keyframes` animations. Implemented as a Drupal block and can be placed in any theme region.
- **Snow** — falling snowflakes driven by JavaScript. Snowflake count, size, speed, and up to three colors are configurable in the admin UI. JavaScript is generated dynamically from saved settings.

## Installation

1. Copy the `custom_newyear` folder to `sites/all/modules/custom/`
2. Enable the module at `Administration → Modules` → find "Custom New Year"
3. Open settings: `Administration → Configuration → User Interface → Custom New Year Settings`

## Settings

### General

| Setting | Default | Description |
|---|---|---|
| Enable Christmas Lightrope | off | Turn on the lightrope |
| Enable Snow Effect | off | Turn on falling snow |

### Snow

| Setting | Default | Recommended range |
|---|---|---|
| Number of snowflakes | `50` | 20–100 |
| Max snowflake size (px) | `40` | 20–60 |
| Falling speed | `0.7` | 0.3–2.0 |
| Primary color | `#fff` | any CSS color |
| Secondary color | — | optional |
| Tertiary color | — | optional |

When multiple colors are set, they are randomly distributed among snowflakes. A color preview is shown directly on the settings page.

### Lightrope styling

| Setting | Default | Description |
|---|---|---|
| Container background color | — | CSS color or `transparent` |
| Top margin (px) | `-15` | negative values move it up |
| Bottom margin (px) | `0` | |
| Custom CSS | — | extra styles for the container |

### Lightrope placement

The lightrope is a **"Christmas Lightrope"** Drupal block. After enabling it in settings, place the block in a region:

`Administration → Structure → Blocks` → find "Christmas Lightrope" → drag to a region → save.

Recommended regions: **Header**, **Page top**, or any area above the content.

## File structure

```
custom_newyear/
├── custom_newyear.info       # Module metadata
├── custom_newyear.module     # Hooks: menu, permission, init, uninstall; snow JS generation
├── custom_newyear.admin.inc  # Settings form with preview
├── custom_newyear.block.inc  # Lightrope block implementation (block_info, block_view)
├── css/
│   ├── styles.scss           # SCSS entry point
│   ├── _variables.scss       # Variables (bulb colors, sizes)
│   ├── _mixins.scss          # Mixins
│   ├── _theme-overrides.scss # Theme-specific overrides
│   ├── components/
│   │   └── _lightrope.scss   # Lightrope component styles
│   └── lightrope.css         # Compiled CSS (loaded by Drupal)
├── js/
│   └── snow-fall.js          # Reference snow script (not loaded directly)
└── SCSS_BUILD_PROCESS.md     # SCSS build instructions
```

## Building CSS from SCSS

```bash
# Install Sass (once)
npm install -g sass

# Compile
sass css/styles.scss css/lightrope.css --style compressed

# Watch for changes
sass css/styles.scss css/lightrope.css --watch
```

The CSS and JS caches are cleared automatically when settings are saved in the admin form.

## Uninstall

On uninstall, the module removes all its variables from the database via `hook_uninstall`.

## Requirements

- Drupal 7.x
- For rebuilding CSS: Node.js + Sass

## License

GPLv2

---

&copy; Petr Selfin — [selfin.pro](https://selfin.pro) | [pro-self.ru](https://pro-self.ru)
