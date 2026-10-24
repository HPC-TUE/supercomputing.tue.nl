// Copy buttons (e.g. the email address on the contact page). Delegated, so it
// keeps working with instant navigation.
document.addEventListener("click", function (e) {
  var btn = e.target.closest("[data-copy]");
  if (!btn || !navigator.clipboard) return;
  navigator.clipboard.writeText(btn.dataset.copy).then(function () {
    var label = btn.textContent;
    btn.textContent = "Copied";
    setTimeout(function () { btn.textContent = label; }, 1500);
  });
});
