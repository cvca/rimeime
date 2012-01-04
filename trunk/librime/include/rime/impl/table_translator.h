// vim: set sts=2 sw=2 et:
// encoding: utf-8
//
// Copyleft 2011 RIME Developers
// License: GPLv3
//
// 2011-07-10 GONG Chen <chen.sst@gmail.com>
//
#ifndef RIME_TABLE_TRANSLATOR_H_
#define RIME_TABLE_TRANSLATOR_H_

#include <string>
#include <rime/common.h>
#include <rime/translation.h>
#include <rime/translator.h>
#include <rime/dict/dictionary.h>

namespace rime {

class TableTranslation : public Translation {
 public:
  TableTranslation(size_t start, size_t end);
  TableTranslation(const DictEntryIterator& iter, size_t start, size_t end);
  virtual bool Next();
  virtual shared_ptr<Candidate> Peek();
  
 protected:
  DictEntryIterator iter_;
  size_t start_;
  size_t end_;
};

class TableTranslator : public Translator {
 public:
  TableTranslator(Engine *engine);
  virtual ~TableTranslator();

  virtual Translation* Query(const std::string &input,
                             const Segment &segment);

 protected:
  scoped_ptr<Dictionary> dict_;
  bool enable_completion_;
};

}  // namespace rime

#endif  // RIME_TABLE_TRANSLATOR_H_
