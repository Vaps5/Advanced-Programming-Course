#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  Corpus tokens;

  auto space_iterators = find_all(source.begin(), source.end(), ::isspace);

  std::transform(space_iterators.begin(), std::prev(space_iterators.end()),
      std::next(space_iterators.begin()),
      std::inserter(tokens, tokens.end()),
      [&source](auto it1, auto it2) {
          return Token(source, it1, it2);
      });

  // Usar std::erase_if en lugar de eliminar manualmente los tokens vacíos
  std::erase_if(tokens, [](const Token& token) {
      return token.content.empty();
  });

  return tokens;
}




std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;

  auto misspelled_view = source | rv::filter([&dictionary](const Token& token) {
      return !dictionary.contains(token.content);
  });

  auto transformed_view = misspelled_view | rv::transform([&dictionary](const Token& token) {
      // Generar sugerencias sin usar un bucle for
      auto suggestions = dictionary 
          | rv::filter([&](const std::string& word) {
              return levenshtein(token.content, word) == 1;
            })
          | rv::transform([](const std::string& word) {
              return word;
            });

      return Mispelling{token, std::set<std::string>(suggestions.begin(), suggestions.end())};
  });

  std::set<Mispelling> misspellings;
  std::ranges::copy_if(transformed_view, std::inserter(misspellings, misspellings.end()),
                       [](const Mispelling& m) {
                           return !m.suggestions.empty();
                       });

  return misspellings;
}


/* Helper methods */

#include "utils.cpp"