# 一般题目

filename:
```text
${question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})
```

```text
${question.content}

\#include "includes/heads.h"
using namespace std;

${question.code}

int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}
```

# LCOF
```text
$!velocityTool.replace(${question.frontendQuestionId}, "剑指 Offer ", "LCOF")
```

```text
${question.content}

\#include "includes/heads.h"
using namespace std;

${question.code}

int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}
```