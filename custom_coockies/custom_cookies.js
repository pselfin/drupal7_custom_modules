/**
 * @file
 * Custom Cookies: скрываем плашку если кука уже есть, вешаем клик на кнопку.
 */

(function ($, Drupal) {
  Drupal.behaviors.customCookies = {
    attach: function (context, settings) {
      var cookieNote = document.getElementById("cookie_note");

      if (!cookieNote || cookieNote.getAttribute("data-cookies-init")) {
        return;
      }
      cookieNote.setAttribute("data-cookies-init", "1");

      var cfg = Drupal.settings.custom_cookies || {};
      var cookieDays = parseInt(cfg.cookie_days, 10) || 90;

      function getCookie(name) {
        var matches = document.cookie.match(
          new RegExp("(?:^|; )" + name.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, "\\$1") + "=([^;]*)")
        );
        return matches ? decodeURIComponent(matches[1]) : undefined;
      }

      function setCookie(name, value, days) {
        var date = new Date();
        date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
        document.cookie = name + "=" + (value || "") + "; expires=" + date.toUTCString() + "; path=/";
      }

      if (getCookie("cookies_policy")) {
        cookieNote.className += " cookie-hidden";
        return;
      }

      var btn = cookieNote.querySelector(".cookie_accept");
      if (btn) {
        btn.addEventListener("click", function () {
          setCookie("cookies_policy", "true", cookieDays);
          cookieNote.className += " cookie-hidden";
        });
      }
    }
  };
})(jQuery, Drupal);
